#ifndef RESISTOR_PAGE_H
#define RESISTOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class resistor_page;
}

class resistor_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit resistor_page(QWidget *parent = 0);
  ~resistor_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::resistor_page *ui;
}

#endif // RESISTOR_PAGE_H