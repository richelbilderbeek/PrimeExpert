#ifndef QTTOOLPRIMEEXPERTMAINDIALOG_H
#define QTTOOLPRIMEEXPERTMAINDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qthideandshowdialog.h"
#include <boost/scoped_ptr.hpp>
#pragma GCC diagnostic pop

namespace Ui {
  class QtToolPrimeExpertMainDialog;
}

namespace ribi {

struct PrimeExpert;

class QtToolPrimeExpertMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtToolPrimeExpertMainDialog(QWidget *parent = 0);
  QtToolPrimeExpertMainDialog(const QtToolPrimeExpertMainDialog&) = delete;
  QtToolPrimeExpertMainDialog& operator=(const QtToolPrimeExpertMainDialog&) = delete;
  ~QtToolPrimeExpertMainDialog() noexcept;

private:
  Ui::QtToolPrimeExpertMainDialog *ui;
  boost::scoped_ptr<PrimeExpert> m_expert;

private slots:
    void on_edit_value_textChanged(QString );
};

} //~namespace ribi

#endif // QTTOOLPRIMEEXPERTMAINDIALOG_H

