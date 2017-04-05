#ifndef INDUCTOR_PAGE_H
#define INDUCTOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class inductor_page;
}

class inductor_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit inductor_page(QWidget *parent = 0);
  ~inductor_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::inductor_page *ui;
}

#endif // INDUCTOR_PAGE_H