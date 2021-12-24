
#ifndef DESKTOP_CHOICE_H
#define DESKTOP_CHOICE_H

#define MX_SUCCESS_PHRASE "Follow me!"

#define MX_FAIL_PHRASE "Perhaps I was wrong about you, Neo."

#define MX_UNDEFINED_PHRASE "Are you sure about that?"

#define MX_RED_PILL 0

#define MX_BLUE_PILL 1

typedef char t_phrase;

t_phrase *choice(int pill);

#endif //DESKTOP_CHOICE_H
