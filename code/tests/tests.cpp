#include <catch2/catch_test_macros.hpp>

TEST_CASE("Different Sim Hash") {
    SimHash sh;
    std::string doc1 = "This is a complex document.";
    std::string doc2 = "This is a simple document.";
    REQUIRE(sh.computeSimHash(doc1) != sh.computeSimHash(doc2));
}

TEST_CASE("Same Sim Hash")
{
    SimHash sh;
    std::string doc1 = "Hello, world!";
    std::string doc2 = "Hello, world!";
    REQUIRE(sh.computeSimHash(doc1) == sh.computeSimHash(doc2));
}

TEST_CASE("High similarity")
{
    SimHash sh;
    std::string doc1 = "The quick brown fox jumps over the lazy dog.";
    std::string doc2 = "The quick brown fox jumped over the lazy dogs.";
    REQUIRE_FALSE(sh.measureSimilarity(doc1, doc2) <= .9);
}

TEST_CASE("Medium similarity")
{
    SimHash sh;
    std::string doc1 = "Machine learning is a subset of artificial intelligence.";
    std::string doc2 = "Machine learning belongs to the domain of artificial intelligence.";
    REQUIRE(sh.measureSimilarity(doc1, doc2) >= .4 && sh.measureSimilarity(doc1, doc2) <= .6);
}

TEST_CASE("Low similarity")
{
    SimHash sh;
    std::string doc1 = "The quick brown fox jumps over the lazy dog.";
    std::string doc2 = "Machine learning belongs to the domain of artificial intelligence.";
    REQUIRE(sh.measureSimilarity(doc1, doc2) <= .1);
}

TEST_CASE("Empty Doc SimHash")
{
    SimHash sh;
    std::string doc1 = "";
    std::string doc2 = "This is not an empty document.";
    REQUIRE(measureSimilarity.(doc1, doc2) <= .1);
}

TEST_CASE("TXT to Document")
{
    SimHash sh;
    std::vector<std::string> docs = sh.convertTXTtoDocument("./data/Long.txt");
    REQUIRE(docs.size() == 2);
}



