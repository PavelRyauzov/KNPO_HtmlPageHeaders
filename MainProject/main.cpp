#include <QCoreApplication>
#include <FunctionsAndDataStructures.h>

int main(int argc, char *argv[])
{

#ifdef TESTING_MODE
    runTest(argc, argv);
#else
    //Основное поведение программы

    return 0;
#endif

    return 0;
}
