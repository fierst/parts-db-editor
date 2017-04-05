#ifndef DIODE_PAGE_H
#define DIODE_PAGE_H

#include <QWizardPage>

namespace Ui {
  class diode_page;
}

class diode_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit diode_page(QWidget *parent = 0);
  ~diode_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::diode_page *ui;
}

#endif // DIODE_PAGE_H