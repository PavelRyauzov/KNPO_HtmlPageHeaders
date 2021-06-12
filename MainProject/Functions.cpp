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

QStringList createTableOfContentsText(QStringList htmlCode)
{
    // Получить теги заголовков "H" из HTML-кода...
    QStringList headerTags = getHeaderTags(htmlCode);

    // Создать список заголовков (переменных структуры Header, содержащих уровень вложенности тега "H" и текст внутри него)
    QList<Header> headers;

    // Для каждого найденного ранее тега заголовка
    for (int i = 0; i < headerTags.length(); i++)
    {
        // Разобрать тег заголовка: получить его уровень вложенности и текст...
        headers << parseHeaderTag(headerTags[i]);
    }

    // Получить блоки вложенности, построенные на основе вложенности тегов "H"
    QList<NestingBlock> nestingBlocks;

    nestingBlocks = getNestingBlocks(headers);

    // Создать текст, в который будем помещать результат - текст оглавления заданной HTML-страницы на основании заголовков “H”, с учетом вложенности
    QStringList tableOfContents;

    // Проанализировать каждый блок вложенности и добавить отступы к тексту заголовков, на основе их вложенности...
    // Для каждого блока вложенности
    for (int i = 0; i < nestingBlocks.length(); i++)
    {
        // Создать вектор, который будет содержать список уровней вложенности всех, имеющихся в блоке тегов
        QVector<int> headerLevels;

        // Для каждого заголовка
        for (int k = 0; k < nestingBlocks[i].headers.length(); k++)
        {
            // Записать уровень вложенности текущего заголовка в вектор
            headerLevels <<  nestingBlocks[i].headers[k].nestingLevel;
        }

        // Отсортировать вектор в порядке возрастания
        bubbleSort(headerLevels);

        // Удалить все повторяющиеся элементы в векторе
        removeDuplicateItems(headerLevels);

       // Для каждого элемента вектора, начиная со второго
       for (int k = 1; k < headerLevels.length(); k++)
       {
           // Для каждого заголовка, начиная со 2
           for (int j = 1; j < nestingBlocks[i].headers.length(); j++)
           {
               // Если уровень вложенности текущего заголовка равен значению текущего элемента вектора
               if (nestingBlocks[i].headers[j].nestingLevel == headerLevels[k])
               {
                 // Записать количество отступов в начале строки с текстом заголовка равное номеру элемента вектора
                 for (int g = 0; g < k; g++)
                 {
                    nestingBlocks[i].headers[j].content = "\t" + nestingBlocks[i].headers[j].content;
                 }
               }
           }
       }
    }

    // Записать в выделенный под результат текст - текст всех заголовков
    // Для каждого блока вложенности
    for (int i = 0; i < nestingBlocks.length(); i++)
    {
        // Для каждого заголовка
        for (int j = 0; j < nestingBlocks[i].headers.length(); j++)
        {
            // Записать в строку выделенного под результат текста, строку с текстом текущего заголовка
            tableOfContents << nestingBlocks[i].headers[j].content;
        }
    }

    // Вернуть текст с результатом
    return tableOfContents;
}

QList<NestingBlock> getNestingBlocks(QList<Header> headers)
{
    // Выделить список под результат - блоки вложенности
    QList<NestingBlock> blocks;

    // Считать, что поиск блоков не завершен
    int end = 0;

    // Пока поиск блоков не завершен
    while (end == 0)
    {
        // Выделить временную переменную под блок (переменную структуры NestingBlock)
        NestingBlock tempBlock;

        // Записать первый заголовок во временный блок
        tempBlock.headers << headers[0];

        // Для каждого заголовка, начиная со второго
        for (int j = 1; j < headers.length(); j++)
        {
            // Если уровень вложенности текущего заголовка больше, чем уровень вложенности первого
            if (headers[j].nestingLevel > headers[0].nestingLevel)
            {
                // Записать текущий заголовок во временный блок
                tempBlock.headers << headers[j];
            }
            // Если уровень вложенности текущего тега заголовка меньше или равен уровню вложенности первого или дошли до последнего тега
            if (headers[j].nestingLevel <= headers[0].nestingLevel || j == headers.length() - 1)
            {
                // Если дошли до последнего тега
                if (j == headers.length() - 1)
                {
                   // Считать, что поиск блоков завершен
                   end = 1;
                }

                // Записать в список, выделенный для результата временный блок
                blocks << tempBlock;

                // Для каждого заголовка во временном блоке
                for (int k = 0; k < tempBlock.headers.length(); k++)
                {
                    // Удалить заголовок
                    headers.removeFirst();
                }

                // Прервать цикл
                break;
            }
        }
    }

    // Вернуть список с результатом
    return blocks;
}

void bubbleSort(QVector<int> &vector)
{
    int temp;

    for (int k = 0; k < vector.length() - 1; k++)
    {
        for (int g = 0; g < vector.length() - k - 1; g++)
        {
            if (vector[g] > vector[g + 1])
            {
                temp = vector[g];
                vector[g] = vector[g + 1];
                vector[g + 1] = temp;
            }
        }
    }
}

void removeDuplicateItems(QVector<int> &vector)
{
    for (int k = 0; k < vector.length(); k++)
    {
        if (vector.count(vector[k]) > 1)
        {
            while (vector.count(vector[k]) != 1)
            {
                vector.removeOne(vector[k]);
            }
        }
    }
}

QStringList generateHtmlPageTableOfContents(QStringList tableOfContents)
{
    // Добавить в начало списка строк, содержащего текст оглавления открывающийся тег ul
    tableOfContents.insert(0, "<ul>");

    // Добавить в конец списка строк, содержащего текст оглавления закрывающийся тег ul
    tableOfContents << "</ul>";

    // Для каждой строки текста с оглавлением кроме первой и последней
    for (int i = 1; i < tableOfContents.length() - 1; i++)
    {
        // Считать чисто отступов равным нулю
        int countTabs = 0;

        // Если текущая строка содержит отступы
        if (tableOfContents[i].contains("\t"))
        {
            int j = 0;

            // Пока текущий символ строки содержит отступы в начале
            while (tableOfContents[i][j] == '\t')
            {
                // Увеличить количеств отступов на 1
                countTabs++;

                // Перейти к следующему символу строки
                j++;
            }

            // Удалить отсупы в начале
            tableOfContents[i].remove(0, countTabs);
        }

        // Если количество отступов равно нулю
        if (countTabs == 0)
        {
            // Добавить в начало текущей строки открывающийся тег li, а в конец закрывающийся тег li
            tableOfContents[i] = "<li>" + tableOfContents[i] + "</li>";
        }
        // Иначе если количество отступов больше нуля
        else if (countTabs > 0)
        {
            // Добавить в начало текущей строки открывающийся тег li, а в конец закрывающийся тег li
            tableOfContents[i] = "<li>" + tableOfContents[i] + "</li>";

            // Повторить некоторое число раз равное количеству отступов
            for (int j = 0; j < countTabs; j++)
            {
                // Добавить в начало текущей строки открывающийся тег ul, а в конец закрывающийся тег ul
                tableOfContents[i] = "<ul>" + tableOfContents[i] + "</ul>";
            }
        }
    }

    // Добавить остальную часть html-страницы
    tableOfContents.insert(0, "<body>");
    tableOfContents.insert(0, "</head>");
    tableOfContents.insert(0, "</style>");
    tableOfContents.insert(0, "}");
    tableOfContents.insert(0, "list-style: none;");
    tableOfContents.insert(0, "li {");
    tableOfContents.insert(0, "<style>");
    tableOfContents.insert(0, "<title>Output data</title>");
    tableOfContents.insert(0, "<meta charset=\"utf-8\">");
    tableOfContents.insert(0, "<head>");
    tableOfContents.insert(0, "<html>");
    tableOfContents.insert(0, "<!DOCTYPE html>");
    tableOfContents << "</html>";

    // Возвращаем результат - сгенерированная html-страница с оглавлением
    return tableOfContents;
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

void deleteAllCommentsInHtmlCode(QStringList &htmlCode)
{
    QRegExp rxCommentHtml("<!--([^.]*)-->");

   // Для каждой строки html-кода
   for (int i = 0; i < htmlCode.length(); i++)
   {
       // Удалить комментарий html
       htmlCode[i].remove(rxCommentHtml);
   }
}
