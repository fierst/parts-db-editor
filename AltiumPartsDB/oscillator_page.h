#ifndef OSCILLATOR_PAGE_H
#define OSCILLATOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class oscillator_page;
}

class oscillator_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit oscillator_page(QWidget *parent = 0);
  ~oscillator_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::oscillator_page *ui;
}

#endif // OSCILLATOR_PAGE_H