#include "stringhelper.h"

StringHelper::StringHelper()
{

}

double StringHelper::qStringToDouble(QString s)
{
    if (s.toDouble() == 0) {
        return atof(s.toStdString().c_str());
    }

    return s.toDouble();
}
