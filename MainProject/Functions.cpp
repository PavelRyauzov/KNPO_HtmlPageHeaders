#include <QTextStream>
#include <QFile>
#include <FunctionsAndDataStructures.h>

QStringList getHeaderTags(QStringList htmlCode)
{
   // Записать весь html-код в одну строку...
   // Выделить строку для html-кода
   QString htmlCodeInOneStr;

   // Для каждой строки данного html-кода
   for (int i = 0; i < htmlCode.size(); i++)
   {
       // Добавить в конец строки выделенной строки текущую строку
       htmlCodeInOneStr.append(htmlCode[i]);
   }

    // Получить все теги заголовков в строке с html-кодом...
    // Регулярное выражение для 6 тегов заголовков html
   QRegExp rxHeaderTags("<h1( *)([^<]*)>([^<]*)</h1>|<h2( *)([^<]*)>([^<]*)</h2>|<h3( *)([^<]*)>([^<]*)</h3>|<h4( *)([^<]*)>([^<]*)</h4>|<h5( *)([^<]*)>([^<]*)</h5>|<h6( *)([^<]*)>([^<]*)</h6>|<h1>([^<]*)</h1>|<h2>([^<]*)</h2>|<h3>([^<]*)</h3>|<h4>([^<]*)</h4>|<h5>([^<]*)</h5>|<h6>([^<]*)</h6>|<H1( *)([^<]*)>([^<]*)</H1>|<H2( *)([^<]*)>([^<]*)</H2>|<H3( *)([^<]*)>([^<]*)</H3>|<H4( *)([^<]*)>([^<]*)</H4>|<H5( *)([^<]*)>([^<]*)</H5>|<H6( *)([^<]*)>([^<]*)</H6>|<H1>([^<]*)</H1>|<H2>([^<]*)</H2>|<H3>([^<]*)</H3>|<H4>([^<]*)</H4>|<H5>([^<]*)</H5>|<H6>([^<]*)</H6>");

    // Список для найденных заголовков
    QStringList headerTags;

    // Считать начальной позицией для поиска начало строки с html-кодом
    int lastPos = 0;

    // Пока в строке с html-кодом найден тег заголовка
    while((lastPos = rxHeaderTags.indexIn(htmlCodeInOneStr, lastPos)) != -1)
    {
        // Считать начальной позицией для поиска позицию, следующую за найденным тегом заголовка
        lastPos += rxHeaderTags.matchedLength();

        // Записать найденный заголовок в список
        headerTags << rxHeaderTags.cap(0);
    }

    // Вернуть список с найденными тегами заголовками
    return headerTags;
}

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

