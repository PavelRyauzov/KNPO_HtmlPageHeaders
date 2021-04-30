#ifndef FUNCTIONSANDDATASTRUCTURES_H
#define FUNCTIONSANDDATASTRUCTURES_H

#include <QList>

class Exception : public std::exception
{
public:
    Exception (QString msg)
    {
        message = msg;
    }

    const char * what() const throw ()
    {
        return message.toStdString().c_str();
    }

private:
    QString message;
};

struct Header
{
    int nestingLevel;

    QString content;
};

struct NestingBlock
{
    QList<Header> headers;
};

/*! Удалить все комментарии в html-коде
 * \brief deleteAllCommentsInHtmlCode
 * \param[in|out] htmlCode - текст, содержащий html-код | текст, содержащий html-код без комментариев
 */
void deleteAllCommentsInHtmlCode(QStringList &htmlCode);

/*! Проверка HTML-кода на корректность в рамках данной задачи
 * \brief htmlCodeCheck
 * \param[in] htmlCode - исходный HTML-код
 * \return результат проверки HTML-кода на корректность в рамках данной задачи
 */
bool isHTMLCodeCorrect(QStringList htmlCode);

/*! Получить теги заголовков "H" из HTML-кода
 * \brief getHeaderTags
 * \param[in] htmlCode - текст, содержащий HTML-код
 * \return текст, содержащий теги заголовков "H"
 */
QStringList getHeaderTags(QStringList htmlCode);

/*! Разобрать тег заголовка: получить уровень вложенности и текст
 * \brief parseHeaderTag
 * \param[in] headerTag - строка, содержащая тег заголовков "H"
 * \return переменная структуры Header, содержая уровень вложенности тега "H" и текст внутри него
 */
Header parseHeaderTag(QString headerTag);

/*! Получить текст оглавления заданной HTML-страницы на основании заголовков “H”, с учетом вложенности
 * \brief createTableOfContentsText
 * \param[in] htmlCode - текст, содержащий HTML-код
 * \return список строк, содержащий текст оглавления, построенного на основании заголовков "H", с учетом их вложенности
 */
QStringList createTableOfContentsText(QStringList htmlCode);

/*! Сгенерировать html-страницу с полученным на вход оглавлением
 * \brief generateHtmlPageTableOfContents
 * \param[in] tableOfContents - текст, содержащий оглавление
 * \return текст, содержащий Html-страницу с оглавлением
 */
QStringList generateHtmlPageTableOfContents(QStringList tableOfContents);

/*! Считать данные из файла по заданному пользователем пути
 * \brief getFileContent
 * \param[in] path - путь, по которому располагается файл
 * \param[out] fileContent - текст, с содержимым файла
 */
void getFileContent(QString path, QStringList &fileContent);

/*! Записать данные в файл
 * \brief writeContentToFile
 * \param[in] path - путь, по которому располагается файл
 * \param[out] content - данные, которые будут помещены в файл
 */
void writeContentToFile(QString path, QStringList content);

#endif // FUNCTIONSANDDATASTRUCTURES_H
