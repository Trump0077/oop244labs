#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds {
   const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
        std::ostream& display(std::ostream&)const;

        operator int() const;
        operator double() const;
        operator const char* () const;
        Chapter& operator=(const Chapter& chapter);
        int operator++();
        int operator--();
    };
    std::ostream& operator<<(std::ostream& os, const Chapter& chapter);
}
#endif


