#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <iostream>
#include <Windows.h>
#include <QTextStream>
#include <QTextCodec>
#include <FunctionsAndDataStructures.h>

using namespace std;

int main(int argc, char *argv[])
{

#ifdef TESTING_MODE
    runTest(argc, argv);
#else
    QString errorMessage;

    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода
    QTextStream cout(stdout);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QString path1 = "C:/Users/rauzo/Desktop/Проект/InputData/example_input.html";
    QString path2 = "C:/Users/rauzo/Desktop/Проект/InputData/output.html";

    try
    {
        if (argc == 3)
       {
            QStringList htmlCode;

            // Считываем данные из файла
            getFileContent(path1, htmlCode);

            // Удаляем все комментарии из html-кода
            deleteAllCommentsInHtmlCode(htmlCode);

            // Получаем текст оглавления
            QStringList tableOfContentsText = createTableOfContentsText(htmlCode);

            // Генерируем html-страницу с оглавлением
            QStringList htmlPage = generateHtmlPageTableOfContents(tableOfContentsText);

            // Записываем результат работы программы в файл
            writeContentToFile(path2, htmlPage);
        }
        else
        {
            throw Exception("Отсутствует нужное кол-во аргументов командной строки.", "0");
        }

    }
    catch (Exception& exception)
    {
        // Если коды ошибок равны ошибкам считывания и записи в файл, то выводим ошибку в консоль
        if (exception.gerErrorCode() == "0" || exception.gerErrorCode() == "1" || exception.gerErrorCode() == "2" || exception.gerErrorCode() == "3" || exception.gerErrorCode() == "4")
        {
            cout << exception.what() << ". " << "Код ошибки: " << exception.gerErrorCode();
            return 0;
        }
        // Запись ошибки корректности html-кода
        else
        {
            errorMessage = errorMessage + exception.what() + ". " + "Код ошибки: " + exception.gerErrorCode();

            QStringList listForErrorMsg;

            listForErrorMsg << errorMessage;

            writeContentToFile(argv[2], listForErrorMsg);
        }
    }

    return 0;
#endif

    return 0;
}
