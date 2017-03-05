#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qtprimeexpertmaindialog.h"

#include <boost/lexical_cast.hpp>
#include <boost/timer.hpp>

#include "about.h"
#include "qtaboutdialog.h"
#include "primeexpert.h"
#include "ui_qtprimeexpertmaindialog.h"
#pragma GCC diagnostic pop

ribi::QtToolPrimeExpertMainDialog::QtToolPrimeExpertMainDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtToolPrimeExpertMainDialog),
    m_expert(new PrimeExpert)
{
  ui->setupUi(this);
  ui->edit_value->setText("2");
}

ribi::QtToolPrimeExpertMainDialog::~QtToolPrimeExpertMainDialog() noexcept
{
  delete ui;
}

void ribi::QtToolPrimeExpertMainDialog::on_edit_value_textChanged(QString s)
{
  ui->text->clear();
  try
  {
    boost::lexical_cast<int>(s.toStdString());
  }
  catch (boost::bad_lexical_cast&)
  {
    ui->text->appendPlainText("NaN");
    return;
  }
  const int value = boost::lexical_cast<int>(s.toStdString());
  if (value < 2)
  {
    ui->text->appendPlainText("Not prime");
    return;
  }
  if (value == 2)
  {
    ui->text->appendPlainText("Prime");
    return;
  }
  const boost::timer t;
  const bool isPrime = m_expert->IsPrime(value);
  const double time = t.elapsed();
  const std::string text
    = std::string(isPrime ? "Prime" : "Not prime")
    + " ("
    + boost::lexical_cast<std::string>(time)
    + " sec)";
  ui->text->appendPlainText(text.c_str());
}

