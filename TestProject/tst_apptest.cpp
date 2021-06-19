#include <QtTest>
#include <FunctionsAndDataStructures.h>

// add necessary includes here

class AppTest : public QObject
{
    Q_OBJECT

public:
    AppTest();
    ~AppTest();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Тестовые ситуации для функции getHeaderTags
    void test_getHeaderTags_HeaderTagsWithoutAttributes();
    void test_getHeaderTags_HeaderTagsWithOneAttribute();
    void test_getHeaderTags_HeaderTagsWithMultipleAttributes();
    void test_getHeaderTags_HeaderTagsWithAnAttributeSeparatedBySeveralSpacesFromTheTagName();
    void test_getHeaderTags_HeaderTagsWithoutText();
    void test_getHeaderTags_TwoIdenticalTitleTagsInARow();
    void test_getHeaderTags_SomeTagsBetweenHeaderTags();
    void test_getHeaderTags_RepeatingNestingHeaderTags();
    void test_getHeaderTags_SomeHeaderTagsInUppercase();
    void test_getHeaderTags_HeaderTagsInUppercaseWithoutAttributes();
    void test_getHeaderTags_HeaderTagsInUppercaseWithOneAttribute();
    void test_getHeaderTags_HeaderTagsInUppercaseWithMultipleAttributes();
    void test_getHeaderTags_HeaderTagsInUppercaseWithAnAttributeSeparatedBySeveralSpacesFromTheTagName();
    void test_getHeaderTags_HeaderTagsInUppercaseWithoutText();
    void test_getHeaderTags_TwoIdenticalTitleTagsInUppercaseInARow();
    void test_getHeaderTags_SomeTagsBetweenHeaderTagsInUppercase();
    void test_getHeaderTags_RepeatingNestingHeaderTagsInUppercase();
    void test_getHeaderTags_OpeningAndClosingTitleTagsOnSeparateLines();
    void test_getHeaderTags_OpeningAndClosingTitleTagsInUppercaseOnSeparateLines();

    // Тестовые ситуации для функции parseHeaderTag
    void test_parseHeaderTag_headerTagWithoutAttributes();
    void test_parseHeaderTag_headerTagWithOneAttribute();
    void test_parseHeaderTag_headerTagWithMultipleAttributes();
    void test_parseHeaderTag_headerTagWithAnAttributeSeparatedBySeveralSpacesFromTheTagName();
    void test_parseHeaderTag_headerTagWithoutText();
    void test_parseHeaderTag_headerTagInUppercaseWithoutAttributes();
    void test_parseHeaderTag_headerTagInUpperWithOneAttribute();
    void test_parseHeaderTag_headerTagInUpperWithMultipleAttributes();
    void test_parseHeaderTag_headerTagInUpperWithAnAttributeSeparatedBySeveralSpacesFromTheTagName();
    void test_parseHeaderTag_headerTagInUpperWithoutText();

    // Тестовые ситуации для функции getNestingBlocks
    void test_getNestingBlocks_OneBlockOfNestingAllTagsAreArrangedInAscendingOrderOfNesting();
    void test_getNestingBlocks_OneBlockOfNestingAllTagsAreArrangedInChaoticNestingOrder();
    void test_getNestingBlocks_OneBlockThereIsOnlyOneTag();
    void test_getNestingBlocks_MultipleNestingBlocksTheSeniorTagOfTheFirstBlockHasANestingLevelGreaterThanTheSecond();
    void test_getNestingBlocks_MultipleNestingBlocksThereIsABlockConsistingOfOneTag();

    // Тестовые ситуации для функции generateHtmlPageTableOfContents
    void test_generateHtmlPageTableOfContents_TheTableOfContentsHasNoIndentationAtTheBeginningOfTheLines();
    void test_generateHtmlPageTableOfContents_TheTableOfContentsIsIndentedAtTheBeginningOfLinesInAscendingOrder();
    void test_generateHtmlPageTableOfContents_TheTableOfContentsIsIndentedAtTheBeginningOfChaoticLines();

    // Тестовые ситуации для функции createTableOfContentsText
    void test_createTableOfContentsText_HeaderTagsAreArrangedInAscendingOrderOfNesting();
    void test_createTableOfContentsText_HeaderTagsAreArrangedInAChaoticNestingOrder();
    void test_createTableOfContentsText_OneHeaderTag();
    void test_createTableOfContentsText_HeaderTagsAtTheSameNestingLevel();

    // Тестовые ситуации для функции deleteAllCommentsInHtmlCode
    void test_deleteAllCommentsInHtmlCode_CommentsAreContainedWithinTags();
    void test_deleteAllCommentsInHtmlCode_CommentsAreContainedOutsideOfTagsOnASeparateLine();
    void test_deleteAllCommentsInHtmlCode_CommentsAreContainedBehindClosingTags();
    void test_deleteAllCommentsInHtmlCode_CommentsAreContainedBothOnSeparateLinesAndBehindClosingTagsAndInsideTags();
};

AppTest::AppTest()
{

}

AppTest::~AppTest()
{

}

void AppTest::initTestCase()
{

}

void AppTest::cleanupTestCase()
{

}

// Тестовые ситуации для функции getHeaderTags
void AppTest::test_getHeaderTags_HeaderTagsWithoutAttributes()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>Header 1</h1>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4>",
                             "<h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1>Header 1</h1>",
                                 "<h2>Header 2</h2>",
                                 "<h3>Header 3</h3>",
                                 "<h4>Header 4</h4>",
                                 "<h5>Header 5</h5>",
                                 "<h6>Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsWithOneAttribute()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1 class = \"default-block\">Header 1</h1>",
                             "<h2 class = \"default-block\">Header 2</h2>",
                             "<h3 class = \"default-block\">Header 3</h3>",
                             "<h4 class = \"default-block\">Header 4</h4>",
                             "<h5 class = \"default-block\">Header 5</h5>",
                             "<h6 class = \"default-block\">Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1 class = \"default-block\">Header 1</h1>",
                                 "<h2 class = \"default-block\">Header 2</h2>",
                                 "<h3 class = \"default-block\">Header 3</h3>",
                                 "<h4 class = \"default-block\">Header 4</h4>",
                                 "<h5 class = \"default-block\">Header 5</h5>",
                                 "<h6 class = \"default-block\">Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsWithMultipleAttributes()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1 class = \"default-block\" width=\"16\" height=\"9\">Header 1</h1>",
                             "<h2 class = \"default-block\" width=\"16\" height=\"9\">Header 2</h2>",
                             "<h3 class = \"default-block\" width=\"16\" height=\"9\">Header 3</h3>",
                             "<h4 class = \"default-block\" width=\"16\" height=\"9\">Header 4</h4>",
                             "<h5 class = \"default-block\" width=\"16\" height=\"9\">Header 5</h5>",
                             "<h6 class = \"default-block\" width=\"16\" height=\"9\">Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1 class = \"default-block\" width=\"16\" height=\"9\">Header 1</h1>",
                                 "<h2 class = \"default-block\" width=\"16\" height=\"9\">Header 2</h2>",
                                 "<h3 class = \"default-block\" width=\"16\" height=\"9\">Header 3</h3>",
                                 "<h4 class = \"default-block\" width=\"16\" height=\"9\">Header 4</h4>",
                                 "<h5 class = \"default-block\" width=\"16\" height=\"9\">Header 5</h5>",
                                 "<h6 class = \"default-block\" width=\"16\" height=\"9\">Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsWithAnAttributeSeparatedBySeveralSpacesFromTheTagName()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1   class = \"default-block\">Header 1</h1>",
                             "<h2   class = \"default-block\">Header 2</h2>",
                             "<h3   class = \"default-block\">Header 3</h3>",
                             "<h4    class = \"default-block\">Header 4</h4>",
                             "<h5   class = \"default-block\">Header 5</h5>",
                             "<h6   class = \"default-block\">Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1   class = \"default-block\">Header 1</h1>",
                                 "<h2   class = \"default-block\">Header 2</h2>",
                                 "<h3   class = \"default-block\">Header 3</h3>",
                                 "<h4    class = \"default-block\">Header 4</h4>",
                                 "<h5   class = \"default-block\">Header 5</h5>",
                                 "<h6   class = \"default-block\">Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsWithoutText()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1></h1>",
                             "<h2></h2>",
                             "<h3></h3>",
                             "<h4></h4>",
                             "<h5></h5>",
                             "<h6></h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1></h1>",
                                 "<h2></h2>",
                                 "<h3></h3>",
                                 "<h4></h4>",
                                 "<h5></h5>",
                                 "<h6></h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_TwoIdenticalTitleTagsInARow()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>Header 1</h1>",
                             "<h1>Header 1</h1>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4>",
                             "<h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1>Header 1</h1>",
                                 "<h1>Header 1</h1>",
                                 "<h3>Header 3</h3>",
                                 "<h4>Header 4</h4>",
                                 "<h5>Header 5</h5>",
                                 "<h6>Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_SomeTagsBetweenHeaderTags()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>Header 1</h1>",
                             "<p>Некоторый текст</p>",
                             "<h2>Header 2</h2>",
                             "<p>Некоторый текст</p>",
                             "<h3>Header 3</h3>",
                             "<p>Некоторый текст</p>",
                             "<h4>Header 4</h4>",
                             "<p>Некоторый текст</p>",
                             "<h5>Header 5</h5>",
                             "<p>Некоторый текст</p>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1>Header 1</h1>",
                                 "<h2>Header 2</h2>",
                                 "<h3>Header 3</h3>",
                                 "<h4>Header 4</h4>",
                                 "<h5>Header 5</h5>",
                                 "<h6>Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_RepeatingNestingHeaderTags()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>Header 1</h1>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<h2>Header 2</h2>",
                             "<h5>Header 5</h5>",
                             "<h2>Header 2</h2>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1>Header 1</h1>",
                                 "<h2>Header 2</h2>",
                                 "<h3>Header 3</h3>",
                                 "<h2>Header 2</h2>",
                                 "<h5>Header 5</h5>",
                                 "<h2>Header 2</h2>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_SomeHeaderTagsInUppercase()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>Header 1</H1>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<H4>Header 4</H4>",
                             "<h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<h2>Header 2</h2>",
                                 "<h3>Header 3</h3>",
                                 "<H4>Header 4</H4>",
                                 "<h5>Header 5</h5>",
                                 "<h6>Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsInUppercaseWithoutAttributes()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>Header 1</H1>",
                             "<H2>Header 2</H2>",
                             "<H3>Header 3</H3>",
                             "<H4>Header 4</H4>",
                             "<H5>Header 5</H5>",
                             "<H6>Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<H2>Header 2</H2>",
                                 "<H3>Header 3</H3>",
                                 "<H4>Header 4</H4>",
                                 "<H5>Header 5</H5>",
                                 "<H6>Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsInUppercaseWithOneAttribute()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1 class = \"default-block\">Header 1</H1>",
                             "<H2 class = \"default-block\">Header 2</H2>",
                             "<H3 class = \"default-block\">Header 3</H3>",
                             "<H4 class = \"default-block\">Header 4</H4>",
                             "<H5 class = \"default-block\">Header 5</H5>",
                             "<H6 class = \"default-block\">Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1 class = \"default-block\">Header 1</H1>",
                                 "<H2 class = \"default-block\">Header 2</H2>",
                                 "<H3 class = \"default-block\">Header 3</H3>",
                                 "<H4 class = \"default-block\">Header 4</H4>",
                                 "<H5 class = \"default-block\">Header 5</H5>",
                                 "<H6 class = \"default-block\">Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsInUppercaseWithMultipleAttributes()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1 class = \"default-block\" width=\"16\" height=\"9\">Header 1</H1>",
                             "<H2 class = \"default-block\" width=\"16\" height=\"9\">Header 2</H2>",
                             "<H3 class = \"default-block\" width=\"16\" height=\"9\">Header 3</H3>",
                             "<H4 class = \"default-block\" width=\"16\" height=\"9\">Header 4</H4>",
                             "<H5 class = \"default-block\" width=\"16\" height=\"9\">Header 5</H5>",
                             "<H6 class = \"default-block\" width=\"16\" height=\"9\">Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1 class = \"default-block\" width=\"16\" height=\"9\">Header 1</H1>",
                                 "<H2 class = \"default-block\" width=\"16\" height=\"9\">Header 2</H2>",
                                 "<H3 class = \"default-block\" width=\"16\" height=\"9\">Header 3</H3>",
                                 "<H4 class = \"default-block\" width=\"16\" height=\"9\">Header 4</H4>",
                                 "<H5 class = \"default-block\" width=\"16\" height=\"9\">Header 5</H5>",
                                 "<H6 class = \"default-block\" width=\"16\" height=\"9\">Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsInUppercaseWithAnAttributeSeparatedBySeveralSpacesFromTheTagName()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1   class = \"default-block\">Header 1</H1>",
                             "<H2   class = \"default-block\">Header 2</H2>",
                             "<H3   class = \"default-block\">Header 3</H3>",
                             "<H4    class = \"default-block\">Header 4</H4>",
                             "<H5   class = \"default-block\">Header 5</H5>",
                             "<H6   class = \"default-block\">Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1   class = \"default-block\">Header 1</H1>",
                                 "<H2   class = \"default-block\">Header 2</H2>",
                                 "<H3   class = \"default-block\">Header 3</H3>",
                                 "<H4    class = \"default-block\">Header 4</H4>",
                                 "<H5   class = \"default-block\">Header 5</H5>",
                                 "<H6   class = \"default-block\">Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_HeaderTagsInUppercaseWithoutText()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1></H1>",
                             "<H2></H2>",
                             "<H3></H3>",
                             "<H4></H4>",
                             "<H5></H5>",
                             "<H6></H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1></H1>",
                                 "<H2></H2>",
                                 "<H3></H3>",
                                 "<H4></H4>",
                                 "<H5></H5>",
                                 "<H6></H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_TwoIdenticalTitleTagsInUppercaseInARow()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>Header 1</H1>",
                             "<H1>Header 1</H1>",
                             "<H3>Header 3</H3>",
                             "<H4>Header 4</H4>",
                             "<H5>Header 5</H5>",
                             "<H6>Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<H1>Header 1</H1>",
                                 "<H3>Header 3</H3>",
                                 "<H4>Header 4</H4>",
                                 "<H5>Header 5</H5>",
                                 "<H6>Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_SomeTagsBetweenHeaderTagsInUppercase()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>Header 1</H1>",
                             "<p>Некоторый текст</p>",
                             "<H2>Header 2</H2>",
                             "<p>Некоторый текст</p>",
                             "<H3>Header 3</H3>",
                             "<p>Некоторый текст</p>",
                             "<H4>Header 4</H4>",
                             "<p>Некоторый текст</p>",
                             "<H5>Header 5</H5>",
                             "<p>Некоторый текст</p>",
                             "<H6>Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<H2>Header 2</H2>",
                                 "<H3>Header 3</H3>",
                                 "<H4>Header 4</H4>",
                                 "<H5>Header 5</H5>",
                                 "<H6>Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_RepeatingNestingHeaderTagsInUppercase()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>Header 1</H1>",
                             "<H2>Header 2</H2>",
                             "<H3>Header 3</H3>",
                             "<H2>Header 2</H2>",
                             "<H5>Header 5</H5>",
                             "<H2>Header 2</H2>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<H2>Header 2</H2>",
                                 "<H3>Header 3</H3>",
                                 "<H2>Header 2</H2>",
                                 "<H5>Header 5</H5>",
                                 "<H2>Header 2</H2>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_OpeningAndClosingTitleTagsOnSeparateLines()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>",
                             "Header 1",
                             "</h1>",
                             "<h2>",
                             "Header 2",
                             "</h2>",
                             "<h3>Header 3",
                             "</h3>",
                             "<h4>",
                             "Header 4",
                             "</h4>",
                             "<h5>",
                             "Header 5",
                             "</h5>",
                             "<h6>",
                             "Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<h1>Header 1</h1>",
                                 "<h2>Header 2</h2>",
                                 "<h3>Header 3</h3>",
                                 "<h4>Header 4</h4>",
                                 "<h5>Header 5</h5>",
                                 "<h6>Header 6</h6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

void AppTest::test_getHeaderTags_OpeningAndClosingTitleTagsInUppercaseOnSeparateLines()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<H1>",
                             "Header 1",
                             "</H1>",
                             "<H2>",
                             "Header 2",
                             "</H2>",
                             "<H3>Header 3",
                             "</H3>",
                             "<H4>",
                             "Header 4",
                             "</H4>",
                             "<H5>",
                             "Header 5",
                             "</H5>",
                             "<H6>",
                             "Header 6</H6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<H1>Header 1</H1>",
                                 "<H2>Header 2</H2>",
                                 "<H3>Header 3</H3>",
                                 "<H4>Header 4</H4>",
                                 "<H5>Header 5</H5>",
                                 "<H6>Header 6</H6>"};

    QStringList functionResult = getHeaderTags(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции поиска тегов заголовка (getHeaderTags)");
}

// Тестовые ситуации для функции parseHeaderTag
void AppTest::test_parseHeaderTag_headerTagWithoutAttributes()
{
    QString inputData = "<h1>Header 1</h1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagWithOneAttribute()
{
    QString inputData = "<h1 width=\"16\">Header 1</h1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagWithMultipleAttributes()
{
    QString inputData = "<h1 width=\"16\" height=\"9\">Header 1</h1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagWithAnAttributeSeparatedBySeveralSpacesFromTheTagName()
{
    QString inputData = "<h1      width=\"16\">Header 1</h1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagWithoutText()
{
    QString inputData = "<h1> </h1>";

    Header referenceData = {1, ""};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagInUppercaseWithoutAttributes()
{
    QString inputData = "<H1>Header 1</H1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagInUpperWithOneAttribute()
{
    QString inputData = "<H1 width=\"16\">Header 1</H1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagInUpperWithMultipleAttributes()
{
    QString inputData = "<H1 width=\"16\" height=\"9\">Header 1</H1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagInUpperWithAnAttributeSeparatedBySeveralSpacesFromTheTagName()
{
    QString inputData = "<H1      width=\"16\">Header 1</H1>";

    Header referenceData = {1, "Header 1"};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

void AppTest::test_parseHeaderTag_headerTagInUpperWithoutText()
{
    QString inputData = "<H1> </H1>";

    Header referenceData = {1, ""};

    Header functionResult = parseHeaderTag(inputData);

    bool isOk = false;

    if (functionResult.nestingLevel == referenceData.nestingLevel && functionResult.content == referenceData.content)
    {
       isOk = true;
    }

    QVERIFY2(isOk, "Ошибка функции разбора тега заголовка (parseHeaderTag)");
}

// Тестовые ситуации для функции getNestingBlocks
void AppTest::test_getNestingBlocks_OneBlockOfNestingAllTagsAreArrangedInAscendingOrderOfNesting()
{
    QList<Header> inputData = {{1, "Header 1"}, {2, "Header 2"}, {3, "Header 3"}, {4, "Header 4"}, {5, "Header 5"}, {6, "Header 6"}};

    QList<NestingBlock> referenceData;

    NestingBlock referenceBlock = {{{1, "Header 1"}, {2, "Header 2"}, {3, "Header 3"}, {4, "Header 4"}, {5, "Header 5"}, {6, "Header 6"}}};

    referenceData << referenceBlock;

    QList<NestingBlock> resultProgram = getNestingBlocks(inputData);

    bool isOk = false;

    for (int j = 0; j < referenceData.length(); j++)
    {
        for (int i = 0; i < referenceData[j].headers.length(); i++)
        {
            if (resultProgram[j].headers[i].content == referenceData[j].headers[i].content && resultProgram[j].headers[i].nestingLevel == referenceData[j].headers[i].nestingLevel)
            {
                isOk = true;
            }
        }
    }

     QVERIFY2(isOk, "Ошибка функции получения блоков вложенности (getNestingBlocks)");
}

void AppTest::test_getNestingBlocks_OneBlockOfNestingAllTagsAreArrangedInChaoticNestingOrder()
{
    QList<Header> inputData = {{3, "Header 3"}, {6, "Header 6"}, {5, "Header 5"}, {4, "Header 4"}};

    QList<NestingBlock> referenceData;

    NestingBlock referenceBlock = {{{3, "Header 3"}, {6, "Header 6"}, {5, "Header 5"}, {4, "Header 4"}}};

    referenceData << referenceBlock;

    QList<NestingBlock> resultProgram = getNestingBlocks(inputData);

    bool isOk = false;

    for (int j = 0; j < referenceData.length(); j++)
    {
        for (int i = 0; i < referenceData[j].headers.length(); i++)
        {
            if (resultProgram[j].headers[i].content == referenceData[j].headers[i].content && resultProgram[j].headers[i].nestingLevel == referenceData[j].headers[i].nestingLevel)
            {
                isOk = true;
            }
        }
    }

     QVERIFY2(isOk, "Ошибка функции получения блоков вложенности (getNestingBlocks)");
}

void AppTest::test_getNestingBlocks_OneBlockThereIsOnlyOneTag()
{
    QList<Header> inputData = {{3, "Header 3"}};

    QList<NestingBlock> referenceData;

    NestingBlock referenceBlock = {{{3, "Header 3"}}};

    referenceData << referenceBlock;

    QList<NestingBlock> resultProgram = getNestingBlocks(inputData);

    bool isOk = false;

    for (int j = 0; j < referenceData.length(); j++)
    {
        for (int i = 0; i < referenceData[j].headers.length(); i++)
        {
            if (resultProgram[j].headers[i].content == referenceData[j].headers[i].content && resultProgram[j].headers[i].nestingLevel == referenceData[j].headers[i].nestingLevel)
            {
                isOk = true;
            }
        }
    }

     QVERIFY2(isOk, "Ошибка функции получения блоков вложенности (getNestingBlocks)");
}

void AppTest::test_getNestingBlocks_MultipleNestingBlocksTheSeniorTagOfTheFirstBlockHasANestingLevelGreaterThanTheSecond()
{
    QList<Header> inputData = {{4, "Header 4"}, {6, "Header 6"}, {5, "Header 5"}, {1, "Header 1"}, {2, "Header 2"}, {3, "Header 3"}};

    QList<NestingBlock> referenceData;

    NestingBlock referenceBlock1 = {{{4, "Header 4"}, {6, "Header 6"}, {5, "Header 5"}}};
    NestingBlock referenceBlock2 = {{{1, "Header 1"}, {2, "Header 2"}, {3, "Header 3"}}};

    referenceData << referenceBlock1; referenceData << referenceBlock2;

    QList<NestingBlock> resultProgram = getNestingBlocks(inputData);

    bool isOk = false;

    for (int j = 0; j < referenceData.length(); j++)
    {
        for (int i = 0; i < referenceData[j].headers.length(); i++)
        {
            if (resultProgram[j].headers[i].content == referenceData[j].headers[i].content && resultProgram[j].headers[i].nestingLevel == referenceData[j].headers[i].nestingLevel)
            {
                isOk = true;
            }
        }
    }

     QVERIFY2(isOk, "Ошибка функции получения блоков вложенности (getNestingBlocks)");
}

void AppTest::test_getNestingBlocks_MultipleNestingBlocksThereIsABlockConsistingOfOneTag()
{
    QList<Header> inputData = {{4, "Header 4"}, {6, "Header 6"}, {5, "Header 5"}, {1, "Header 1"}, {2, "Header 2"}, {3, "Header 3"}};

    QList<NestingBlock> referenceData;

    NestingBlock referenceBlock1 = {{{4, "Header 4"}, {6, "Header 6"}, {5, "Header 5"}}};
    NestingBlock referenceBlock2 = {{{3, "Header 3"}}};

    referenceData << referenceBlock1; referenceData << referenceBlock2;

    QList<NestingBlock> resultProgram = getNestingBlocks(inputData);

    bool isOk = false;

    for (int j = 0; j < referenceData.length(); j++)
    {
        for (int i = 0; i < referenceData[j].headers.length(); i++)
        {
            if (resultProgram[j].headers[i].content == referenceData[j].headers[i].content && resultProgram[j].headers[i].nestingLevel == referenceData[j].headers[i].nestingLevel)
            {
                isOk = true;
            }
        }
    }

     QVERIFY2(isOk, "Ошибка функции получения блоков вложенности (getNestingBlocks)");
}

// Тестовые ситуации для функции generateHtmlPageTableOfContents
void AppTest::test_generateHtmlPageTableOfContents_TheTableOfContentsHasNoIndentationAtTheBeginningOfTheLines()
{
    QStringList inputData = {"Header 1",
                             "Header 2",
                             "Header 3",
                             "Header 4",
                             "Header 5",
                             "Header 6"};

    QStringList referenceData = {"<!DOCTYPE html>",
                                 "<html>",
                                 "<head>",
                                 "<meta charset=\"utf-8\">",
                                 "<title>Output data</title>",
                                 "<style>",
                                 "li {",
                                 "list-style: none;",
                                 "}",
                                 "</style>",
                                 "</head>",
                                 "<body>",
                                 "<ul>",
                                 "<li>Header 1</li>",
                                 "<li>Header 2</li>",
                                 "<li>Header 3</li>",
                                 "<li>Header 4</li>",
                                 "<li>Header 5</li>",
                                 "<li>Header 6</li>",
                                 "</ul>",
                                 "</html>"};

    QStringList functionResult = generateHtmlPageTableOfContents(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_generateHtmlPageTableOfContents_TheTableOfContentsIsIndentedAtTheBeginningOfLinesInAscendingOrder()
{
    QStringList inputData = {"Header 1",
                             "\tHeader 2",
                             "\t\tHeader 3",
                             "\t\t\tHeader 4",
                             "\t\t\t\tHeader 5",
                             "\t\t\t\t\tHeader 6"};

    QStringList referenceData = {"<!DOCTYPE html>",
                                 "<html>",
                                 "<head>",
                                 "<meta charset=\"utf-8\">",
                                 "<title>Output data</title>",
                                 "<style>",
                                 "li {",
                                 "list-style: none;",
                                 "}",
                                 "</style>",
                                 "</head>",
                                 "<body>",
                                 "<ul>",
                                 "<li>Header 1</li>",
                                 "<ul><li>Header 2</li></ul>",
                                 "<ul><ul><li>Header 3</li></ul></ul>",
                                 "<ul><ul><ul><li>Header 4</li></ul></ul></ul>",
                                 "<ul><ul><ul><ul><li>Header 5</li></ul></ul></ul></ul>",
                                 "<ul><ul><ul><ul><ul><li>Header 6</li></ul></ul></ul></ul></ul>",
                                 "</ul>",
                                 "</html>"};

    QStringList functionResult = generateHtmlPageTableOfContents(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_generateHtmlPageTableOfContents_TheTableOfContentsIsIndentedAtTheBeginningOfChaoticLines()
{
    QStringList inputData = {"Header 1",
                             "\t\tHeader 3",
                             "\tHeader 2",
                             "\t\t\tHeader 4",
                             "Header 1",
                             "\tHeader 6"};

    QStringList referenceData = {"<!DOCTYPE html>",
                                 "<html>",
                                 "<head>",
                                 "<meta charset=\"utf-8\">",
                                 "<title>Output data</title>",
                                 "<style>",
                                 "li {",
                                 "list-style: none;",
                                 "}",
                                 "</style>",
                                 "</head>",
                                 "<body>",
                                 "<ul>",
                                 "<li>Header 1</li>",
                                 "<ul><ul><li>Header 3</li></ul></ul>",
                                 "<ul><li>Header 2</li></ul>",
                                 "<ul><ul><ul><li>Header 4</li></ul></ul></ul>",
                                 "<li>Header 1</li>",
                                 "<ul><li>Header 6</li></ul>",
                                 "</ul>",
                                 "</html>"};

    QStringList functionResult = generateHtmlPageTableOfContents(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

// Тестовые ситуации для функции createTableOfContentsText
void AppTest::test_createTableOfContentsText_HeaderTagsAreArrangedInAscendingOrderOfNesting()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h1>Header 1</h1>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4>",
                             "h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"Header 1",
                                 "\tHeader 2",
                                 "\t\tHeader 3",
                                 "\t\t\tHeader 4",
                                 "\t\t\t\tHeader 6"};

    QStringList functionResult = createTableOfContentsText(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_createTableOfContentsText_HeaderTagsAreArrangedInAChaoticNestingOrder()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h4>Header 4</h4>",
                             "<h6>Header 6</h6>",
                             "<h5>Header 5</h5>",
                             "<h3>Header 3</h3>",
                             "<h1>Header 1</h1>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4>",
                             "<h3>Header 3</h3>",
                             "<h2>Header 2</h2>",
                             "h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"Header 4",
                                 "\t\tHeader 6",
                                 "\tHeader 5",
                                 "Header 3",
                                 "Header 1",
                                 "\tHeader 2",
                                 "\t\tHeader 3",
                                 "\t\t\tHeader 4",
                                 "\t\tHeader 3",
                                 "\tHeader 2"};

    QStringList functionResult = createTableOfContentsText(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_createTableOfContentsText_OneHeaderTag()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h4>Header 4</h4>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"Header 4"};

    QStringList functionResult = createTableOfContentsText(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_createTableOfContentsText_HeaderTagsAtTheSameNestingLevel()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"Header 3",
                                 "Header 3",
                                 "Header 3",
                                 "Header 3",
                                 "Header 3"};

    QStringList functionResult = createTableOfContentsText(inputData);

    QVERIFY2(functionResult == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

// Тестовые ситуации для функции deleteAllCommentsInHtmlCode
void AppTest::test_deleteAllCommentsInHtmlCode_CommentsAreContainedWithinTags()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h4<!-- c2 -->>Header 4</h4>",
                             "<h6>Header 6</h6>",
                             "<h5>Header 5</h5>",
                             "<h3>Header 3</h3>",
                             "<h2>Header 2</h2<!-- c2 -->>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4> ",
                             " <<!-- c2 -->h3>Header 3</h3>",
                             "<h2>Header 2</h2>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h4>Header 4</h4>",
                             "<h6>Header 6</h6>",
                             "<h5>Header 5</h5>",
                             "<h3>Header 3</h3>",
                             "<h2>Header 2</h2>",
                             "<h3>Header 3</h3>",
                             "<h4>Header 4</h4> ",
                             " <h3>Header 3</h3>",
                             "<h2>Header 2</h2>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    deleteAllCommentsInHtmlCode(inputData);

    QVERIFY2(inputData == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_deleteAllCommentsInHtmlCode_CommentsAreContainedOutsideOfTagsOnASeparateLine()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<!-- c2 -->",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<!-- c2 -->",
                             "<h1>Header 1</h1> ",
                             "<h2>Header 2</h2> ",
                             "<!-- c2 -->",
                             "<h3>Header 3</h3>",
                             "<!-- c2 -->",
                             "<h4>Header 4</h4>",
                             "<h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "",
                             "<meta charset=\"utf-8\">",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "",
                             "<h1>Header 1</h1> ",
                             "<h2>Header 2</h2> ",
                             "",
                             "<h3>Header 3</h3>",
                             "",
                             "<h4>Header 4</h4>",
                             "<h5>Header 5</h5>",
                             "<h6>Header 6</h6>",
                             "</body>",
                             "</html>"};

    deleteAllCommentsInHtmlCode(inputData);

    QVERIFY2(inputData == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_deleteAllCommentsInHtmlCode_CommentsAreContainedBehindClosingTags()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\"> <!-- c2 -->",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h3>Header 3</h3> <!-- c2 -->",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>   <!-- c2 -->",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<meta charset=\"utf-8\"> ",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<h3>Header 3</h3> ",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>   ",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "</body>",
                             "</html>"};

    deleteAllCommentsInHtmlCode(inputData);

    QVERIFY2(inputData == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

void AppTest::test_deleteAllCommentsInHtmlCode_CommentsAreContainedBothOnSeparateLinesAndBehindClosingTagsAndInsideTags()
{
    QStringList inputData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "<!-- c2 -->",
                             "<meta charset=\"utf-8\"> <!-- c2 -->",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "<!-- c2 -->",
                             "<h3>Header 3</h3> <!-- c2 -->",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>   <!-- c2 -->",
                             "<h3>Header 3</h3<!-- c2 -->>",
                             "<h3>Header 3</h3>",
                             "</body>",
                             "</html>"};

    QStringList referenceData = {"<!DOCTYPE html>",
                             "<html>",
                             "<head>",
                             "",
                             "<meta charset=\"utf-8\"> ",
                             "<title>Input data</title>",
                             "</head>",
                             "<body>",
                             "",
                             "<h3>Header 3</h3> ",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>   ",
                             "<h3>Header 3</h3>",
                             "<h3>Header 3</h3>",
                             "</body>",
                             "</html>"};

    deleteAllCommentsInHtmlCode(inputData);

    QVERIFY2(inputData == referenceData, "Ошибка функции генерации html-страницы с оглавлением (generateHtmlPageTableOfContents)");
}

#include "tst_apptest.moc"

int runTest(int argc, char *argv[]) {

    AppTest t;
    return QTest::qExec(&t, argc, argv);
}

#define TESTING_MODE

#include "../MainProject/main.cpp"

