#include <catch2/catch_test_macros.hpp>

TEST_CASE("basicSimHash1") {
    SimHash sh;
    std::string doc1 = "This is a simple document.";
    std::string doc2 = "This is a simple document!";
    REQUIRE(sh.compute(doc1) != sh.compute(doc2));
}

TEST_CASE("basicSimHash2")
{
    SimHash sh;
    std::string doc1 = "Hello, world!";
    std::string doc2 = "Hello, world!";
    REQUIRE(sh.compute(doc1) == sh.compute(doc2));
}

TEST_CASE("similarityCheck1")
{
    SimHash sh;
    std::string doc1 = "The quick brown fox jumps over the lazy dog.";
    std::string doc2 = "The quick brown fox jumped over the lazy dogs.";
    REQUIRE_FALSE(sh.isSimilar(doc1, doc2));
}

TEST_CASE("similarityCheck2")
{
    SimHash sh;
    std::string doc1 = "Machine learning is a subset of artificial intelligence.";
    std::string doc2 = "Machine learning belongs to the domain of artificial intelligence.";
    REQUIRE(sh.isSimilar(doc1, doc2));
}

TEST_CASE("largeDocumentSimHash")
{
    SimHash sh;
    std::string doc1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum.";
    std::string doc2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum.";
    REQUIRE(sh.compute(doc1) == sh.compute(doc2));
}

TEST_CASE("emptyDocumentSimHash")
{
    SimHash sh;
    std::string doc1 = "";
    std::string doc2 = "This is not an empty document.";
    REQUIRE_FALSE(sh.isSimilar(doc1, doc2));
}



