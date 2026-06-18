/*
Why is this?? To test  
How does argumet checking work in python 

*/

#include <stdio.h>

typedef long Py_ssize_t;


typedef struct {
    Py_ssize_t co_argcount;
    Py_ssize_t co_kwonlyargcount;
    int co_flags;

} PyCodeObject;


void too_many_positional(
    PyCodeObject *co,
    Py_ssize_t given,
    Py_ssize_t kwonly_given,
    Py_ssize_t defcount,
    const char *qualname
) {
    int plural;

    Py_ssize_t co_argcount = co->co_argcount;

    if (defcount) {
        Py_ssize_t atleast = co_argcount - defcount;

        printf("TypeError: %s() takes from %ld to %ld positional arguments"
            "but %ld were given\n",
            qualname, 
            atleast,
            co_argcount,
            given

            );
    }
    else {
        plural = (co_argcount != 1);

        printf("TypeError: %s() takes %ld positional argument%s "
            "but %ld were given\n",
            qualname,
            co_argcount,
            plural ? "s" : "",
            given
        );
    }
}

int main(void) {
    PyCodeObject co = {
        .co_argcount = 2,
        .co_kwonlyargcount = 0,
        .co_flags = 0
    };

    too_many_positional(
        &co,
        3,
        0,
        0,
        "f"
    );

    return 0;
} 
