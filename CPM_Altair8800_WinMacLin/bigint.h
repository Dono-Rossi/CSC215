struct bigint {
    char negative;
    char numdigits;
    char* digits;
};

void set_bigint();
char* get_bigint();
void add_bigint();
void sub_bigint();
void add_abs();
void sub_abs();
char* compare_abs();

