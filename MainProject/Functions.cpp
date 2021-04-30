#include <QTextStream>
#include <QFile>
#include <FunctionsAndDataStructures.h>

void getFileContent(QString path, QStringList &fileContent)
{
    QFile mFile(path);

    // Если файл не удалось открыть
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        throw Exception("Не удалось открыть входной файл");
    }
    else
    {
        QTextStream stream(&mFile);
        QString buffer;

        while (stream.readLineInto((&buffer)))
        {
            fileContent << buffer;
        }

        mFile.flush();
        mFile.close();
    }
}

void writeContentToFile(QString path, QStringList content)
{
    QFile file(path);

    // Если файл не удалось открыть
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
       throw Exception("Не удалось открыть выходной файл");
    }
    else
    {
        QTextStream out(&file);

        foreach(QString line, content)
        {
             out << line << Qt::endl;
        }
    }
}

