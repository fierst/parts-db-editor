#ifndef ELECTROMECHANICAL_PAGE_H
#define ELECTROMECHANICAL_PAGE_H

#include <QWizardPage>

namespace Ui {
  class electromechanical_page;
}

class electromechanical_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit electromechanical_page(QWidget *parent = 0);
  ~electromechanical_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::electromechanical_page *ui;
}

#endif // ELECTROMECHANICAL_PAGE_H