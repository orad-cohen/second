

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p, b and and f")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "Pillsbury frosting is the best";
    CHECK(find(text, "Pillsbury") == string("Pillsbury"));
    CHECK(find(text, "billsbury") == string("Pillsbury"));
    CHECK(find(text, "Billsbury") == string("Pillsbury"));
    CHECK(find(text, "pillspury") == string("Pillsbury"));
    CHECK(find(text, "BillsBury") == string("Pillsbury"));
    CHECK(find(text, "PillsPury") == string("Pillsbury"));
    CHECK(find(text, "frosting") == string("frosting"));
    CHECK(find(text, "Frosting") == string("frosting"));
    CHECK(find(text, "prosting") == string("frosting"));
    CHECK(find(text, "Prosting") == string("frosting"));
    CHECK(find(text, "brosting") == string("frosting"));
    CHECK(find(text, "Brosting") == string("frosting"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    text = "The corona virus is contiguous";
    CHECK(find(text, "corona") == string("corona"));
    CHECK(find(text, "corona") == string("corona"));
    CHECK(find(text, "corona") == string("corona"));
    CHECK(find(text, "corona") == string("corona"));
    CHECK(find(text, "conTigUous") == string("contiguous"));
    CHECK(find(text, "cOntiguoUs") == string("contiguous"));
    CHECK(find(text, "contiGuous") == string("contiguous"));
    CHECK(find(text, "CONtiguouS") == string("contiguous"));
    CHECK(find(text, "contiguous") == string("contiguous"));
}

TEST_CASE("Test replacement of y and v"){

    string text = "The war diminished the vitality of the industry.";
    CHECK(find(text, "vitality") == string("vitality"));
    CHECK(find(text, "yitality") == string("vitality"));
    CHECK(find(text, "vitalitv") == string("vitality"));
    CHECK(find(text, "yitalitv") == string("vitality"));
    CHECK(find(text, "VitaLity") == string("vitality"));
    CHECK(find(text, "YitalitV") == string("vitality"));
    CHECK(find(text, "VItaLiTv") == string("vitality"));
    CHECK(find(text, "YiTalitV") == string("vitality"));
}

TEST_CASE("Test replacement of g and j"){
    string text = "The DJ has highjacked the show";
    CHECK(find(text, "dj") == string("dj"));
    CHECK(find(text, "dj") == string("dj"));
    CHECK(find(text, "dj") == string("dj"));
    CHECK(find(text, "highjacked") == string("highjacked"));
    CHECK(find(text, "highGacked") == string("highjacked"));
    CHECK(find(text, "hiJhjacked") == string("highjacked"));
    CHECK(find(text, "hijhGacked") == string("highjacked"));
    CHECK(find(text, "hiJhGacked") == string("highjacked"));
}

TEST_CASE("Test replacement of c,k and q"){
    string text = "The crack in the wall is quite big";
    CHECK(find(text, "quite") == string("quite"));
    CHECK(find(text, "Quite") == string("quite"));
    CHECK(find(text, "Cuite") == string("quite"));
    CHECK(find(text, "cuite") == string("quite"));
    CHECK(find(text, "kuite") == string("quite"));
    CHECK(find(text, "Kuite") == string("quite"));
    CHECK(find(text, "crack") == string("crack"));
    CHECK(find(text, "cracc") == string("crack"));
    CHECK(find(text, "crakk") == string("crack"));
    CHECK(find(text, "krack") == string("crack"));
    CHECK(find(text, "KracC") == string("crack"));
    CHECK(find(text, "CraKC") == string("crack"));
    CHECK(find(text, "krakk") == string("crack"));
    CHECK(find(text, "KraKk") == string("crack"));
    CHECK(find(text, "crACC") == string("crack"));
}
TEST_CASE("Test replacement of s and z")
{
    string text = "xxx sense yyy";
    CHECK(find(text, "sense") == string("sense"));
    CHECK(find(text, "senze") == string("sense"));
    CHECK(find(text, "zense") == string("sense"));
    CHECK(find(text, "zenze") == string("sense"));
    CHECK(find(text, "Sense") == string("sense"));
    CHECK(find(text, "Senze") == string("sense"));
    CHECK(find(text, "zenSe") == string("sense"));
    CHECK(find(text, "Zense") == string("sense"));
    CHECK(find(text, "Zense") == string("sense"));
    CHECK(find(text, "ZenZe") == string("sense"));
    CHECK(find(text, "SenSe") == string("sense"));
    CHECK(find(text, "ZenSe") == string("sense"));
}

TEST_CASE("Test replacement of d and t")
{
    string text = "xxx dad yyy";
    CHECK(find(text, "dad") == string("dad"));
    CHECK(find(text, "dat") == string("dad"));
    CHECK(find(text, "tad") == string("dad"));
    CHECK(find(text, "tat") == string("dad"));
    CHECK(find(text, "Dad") == string("dad"));
    CHECK(find(text, "Dat") == string("dad"));
    CHECK(find(text, "Tad") == string("dad"));
    CHECK(find(text, "Tat") == string("dad"));
    CHECK(find(text, "daD") == string("dad"));
    CHECK(find(text, "daT") == string("dad"));
    CHECK(find(text, "DaD") == string("dad"));
    CHECK(find(text, "TaT") == string("dad"));
}

TEST_CASE("Test replacement of o and u")
{
    string text = "xxx hour yyy";
    CHECK(find(text, "hour") == string("hour"));
    CHECK(find(text, "huor") == string("hour"));
    CHECK(find(text, "hoor") == string("hour"));
    CHECK(find(text, "huur") == string("hour"));
    CHECK(find(text, "hOur") == string("hour"));
    CHECK(find(text, "hOor") == string("hour"));
    CHECK(find(text, "hoUr") == string("hour"));
    CHECK(find(text, "huUr") == string("hour"));
    CHECK(find(text, "hOUr") == string("hour"));
    CHECK(find(text, "hUor") == string("hour"));
    CHECK(find(text, "hUUr") == string("hour"));
    CHECK(find(text, "hUur") == string("hour"));
    CHECK(find(text, "hOOr") == string("hour"));
}

TEST_CASE("Test replacement of i and y")
{
    string text = "xxx hailey yyy";
    CHECK(find(text, "hailey") == string("hailey"));
    CHECK(find(text, "hailei") == string("hailey"));
    CHECK(find(text, "haileI") == string("hailey"));
    CHECK(find(text, "haileY") == string("hailey"));
    CHECK(find(text, "haIley") == string("hailey"));
    CHECK(find(text, "haIleY") == string("hailey"));
    CHECK(find(text, "haIleI") == string("hailey"));
    CHECK(find(text, "hayley") == string("hailey"));
    CHECK(find(text, "haylei") == string("hailey"));
    CHECK(find(text, "hayleY") == string("hailey"));
    CHECK(find(text, "hayleI") == string("hailey"));
    CHECK(find(text, "haYley") == string("hailey"));
    CHECK(find(text, "haYleY") == string("hailey"));
}
