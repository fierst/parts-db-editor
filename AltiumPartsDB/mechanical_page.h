#ifndef MECHANICAL_PAGE_H
#define MECHANICAL_PAGE_H

#include <QWizardPage>

namespace Ui {
  class mechanical_page;
}

class mechanical_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit mechanical_page(QWidget *parent = 0);
  ~mechanical_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::mechanical_page *ui;
}

#endif // MECHANICAL_PAGE_H