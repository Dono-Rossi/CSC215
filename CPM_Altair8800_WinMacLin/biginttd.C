#include "BIGINT.H"
#include "BDSCTEST.H"

main() {
    START_TESTING("BIGINTTD.C");

    TEST_CASE("Read and write bigint 1234567") {
        struct bigint bi;
        set_bigint("1234567", &bi);
        ASSERT_STR(get_bigint(bi), "1234567");
    }
    TEST_CASE("Add two single digit numbers"){
        struct bigint bi1;
        struct bigint bi2;
        struct bigint biout;
        set_bigint("2", &bi1);
        set_bigint("4", &bi2);
        ASSERT_STR(get_bigint(bi1), "2");
        ASSERT_STR(get_bigint(bi2), "4");
        add_bigint(bi1,bi2,biout);
        ASSERT_STR(get_bigint(biout), "6");
}
    TEST_CASE("Add two double digit numbers"){
        set_bigint("12", &bi1);
        set_bigint("14", &bi2);
        ASSERT_STR(get_bigint(bi1), "12");
        ASSERT_STR(get_bigint(bi2), "14");
        add_bigint(bi1,bi2,biout);
        ASSERT_STR(get_bigint(biout), "26");
}
    TEST_CASE("Add two ten digit numbers"){
        set_bigint("1234567891", &bi1);
        set_bigint("1987654321", &bi2);
        ASSERT_STR(get_bigint(bi1), "1234567891");
        ASSERT_STR(get_bigint(bi2), "1987654321");
        add_bigint(bi1,bi2,biout);
        ASSERT_STR(get_bigint(biout), "3222222212");
}
    TEST_CASE("Add two different length numbers"){
        set_bigint("2298", &bi1);
        set_bigint("43", &bi2);
        ASSERT_STR(get_bigint(bi1), "2298");
        ASSERT_STR(get_bigint(bi2), "43");
        add_bigint(bi1,bi2,biout);
        ASSERT_STR(get_bigint(biout), "2341");
}
    TEST_CASE("Add two different length numbers"){
        set_bigint("67", &bi1);
        set_bigint("6700", &bi2);
        ASSERT_STR(get_bigint(bi1), "67");
        ASSERT_STR(get_bigint(bi2), "6700");
        add_bigint(bi1,bi2,biout);
        ASSERT_STR(get_bigint(biout), "6767");
}
    END_TESTING();
}
