#ifndef POWER_PAGE_H
#define POWER_PAGE_H

#include <QWizardPage>

namespace Ui {
  class power_page;
}

class power_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit power_page(QWidget *parent = 0);
  ~power_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::power_page *ui;
}

#endif // POWER_PAGE_H