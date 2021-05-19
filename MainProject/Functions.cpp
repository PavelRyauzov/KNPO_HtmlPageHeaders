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

Header parseHeaderTag(QString headerTag)
{
    // Регулярные выражения для тегов заголовков с атрибутами и без атрибутов
    QRegExp rxHeaderTagWithoutAttribute("<h1>([^<]*)</h1>|<h2>([^<]*)</h2>|<h3>([^<]*)</h3>|<h4>([^<]*)</h4>|<h5>([^<]*)</h5>|<h6>([^<]*)</h6>|<H1>([^<]*)</H1>|<H2>([^<]*)</H2>|<H3>([^<]*)</H3>|<H4>([^<]*)</H4>|<H5>([^<]*)</H5>|<H6>([^<]*)</H6>");
    QRegExp rxHeaderTagWithAttribute("<h1( *)([^<]*)>([^<]*)</h1>|<h2( *)([^<]*)>([^<]*)</h2>|<h3( *)([^<]*)>([^<]*)</h3>|<h4( *)([^<]*)>([^<]*)</h4>|<h5( *)([^<]*)>([^<]*)</h5>|<h6( *)([^<]*)>([^<]*)</h6>|<H1( *)([^<]*)>([^<]*)</H1>|<H2( *)([^<]*)>([^<]*)</H2>|<H3( *)([^<]*)>([^<]*)</H3>|<H4( *)([^<]*)>([^<]*)</H4>|<H5( *)([^<]*)>([^<]*)</H5>|<H6( *)([^<]*)>([^<]*)</H6>");

    //Регулярные выражения для открывающихся тегов заголовка и закрывающихся
    QRegExp rxOpenTag("h[1-6]|H[1-6]");
    QRegExp rxCloseTag("/h[1-6]|/H[1-6]");

    // Создать переменную структуры Header, сюда будем помещать результат - разобранный заголовок
    Header parsedHeader;

    // Если в строке с тегом содержится тег "H" без аттрибута
    if (rxHeaderTagWithoutAttribute.exactMatch(headerTag))
    {
        // Найти и записать в качестве результата уровень вложенности и текст тега заголовка...


        int lastPos = 0;

        // Если в строке с тегом  найден тег заголовка без аттрибута
        if ((lastPos = rxHeaderTagWithoutAttribute.indexIn(headerTag, lastPos)) != -1)
        {
            // Определить текст внутри тега
            int pos = 0;

            // Создать строку буффер
            QString temp;

            // Если в строке с тегом  найден открывающийся тег заголовка
            if ((pos = rxOpenTag.indexIn(headerTag, pos)) != -1)
            {
                // Записать строку с тегом в строку буффер
                temp = headerTag;

                // Удалить открывающийся тег из строки буффера
                temp.remove(pos - 1, pos + 3);
            }

            pos = 0;

            // Если в строке буффер найден закрывающийся тег заголовка
            if ((pos = rxCloseTag.indexIn(temp, pos)) != -1)
            {
                // Удалить закрывающйися тег из строки буффера
                temp.remove(pos - 1, pos + 4);
            }

            // Удалить пробелы в начале и в конце строки буффера
            temp = temp.trimmed();

            // Записать текст, что остался в строке буффера в качестве результата - текст внутри тега "H"
            parsedHeader.content = temp;

            // Определить уровень вложенности тега
            pos = 0;

            // Если в строке с тегом  найден открывающийся тег заголовка
            if ((pos = rxOpenTag.indexIn(headerTag, pos)) != -1)
            {
                // Записать 2 символ строки с тегом в качестве результата - уровень вложенности тега "H"
                parsedHeader.nestingLevel = QString(rxOpenTag.cap(0)[1]).toInt();
            }
        }
    }
    // Иначе если в строке с тегом содержится тег "H" с аттрибутом
    else if (rxHeaderTagWithAttribute.exactMatch(headerTag))
    {
        int lastPos = 0;

        // Если в строке найден тег заголовка с аттрибутом
        if ((lastPos = rxHeaderTagWithAttribute.indexIn(headerTag, lastPos)) != -1)
        {
            // Определить текст внутри тега
            int pos = 0;

            // Создать строку буффер
            QString temp;

            QRegExp closeBracket(">");

            // Если в строке с тегом  найден конец закрывающегося тега заголовка
            if ((pos = closeBracket.indexIn(headerTag, pos)) != -1)
            {
                // Записать строку с тегом в строку буффер
                temp = headerTag;

                 // Удалить открывающийся тег из строки буффера
                temp.remove(0, pos + 1);
            }

            pos = 0;

            // Если в строке буффер найден закрывающийся тег заголовка
            if ((pos = rxCloseTag.indexIn(temp, pos)) != -1)
            {
                 // Удалить закрывающйися тег из строки буффера
                temp.remove(pos - 1, pos + 4);
            }

            // Удалить пробелы в начале и в конце строки буффера
            temp = temp.trimmed();

            // Записать текст, что остался в строке буффера в качестве результата - текст внутри тега "H"
            parsedHeader.content = temp;

            // Определить уровень вложенности тега
            pos = 0;

             // Если в строке с тегом  найден открывающийся тег заголовка
            if ((pos = rxOpenTag.indexIn(headerTag, pos)) != -1)
            {
                // Записать 2 символ строки с тегом в качестве результата - уровень вложенности тега "H"
                parsedHeader.nestingLevel = QString(rxOpenTag.cap(0)[1]).toInt();
            }
        }
    }

    return parsedHeader;
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

