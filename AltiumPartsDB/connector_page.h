#ifndef CONNECTOR_PAGE_H
#define CONNECTOR_PAGE_H

#include <QWizardPage>

namespace Ui {
  class connector_page;
}

class connector_page : public QWizardPage
{
  Q_OBJECT

public:
  explicit connector_page(QWidget *parent = 0);
  ~connector_page();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::connector_page *ui;
}

#endif // CONNECTOR_PAGE_H