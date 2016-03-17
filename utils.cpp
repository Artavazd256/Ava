#include "utils.h"
#include <assert.h>
#include <QMessageBox>
void Utils::showMessage(const QString &msg)
{
    assert(msg != NULL);
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}
