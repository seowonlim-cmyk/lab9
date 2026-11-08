// 3. 클래스1Ptr.h: 클래스1Ptr 클래스 정의


// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다.


// private 멤버변수 선언: 클래스1형을 가리키는 포인터


// public 멤버함수 정의


// -생성자, 소멸자, 복사생성자, 복사=연산자, 이동생성자, 이동=연산자


// -print: 멤버변수가 가리키는 데이터가 있을 경우 표준스트림으로 출력, 없으면 no data (nullptr) 출력
#pragma once
#include "book.h"


namespace SeowonLim2348078
{
    class bookPtr
    {
        book* bPtr;
        public:
        bookPtr(const book& b = book{"bookTitle", 1, 10000}): bPtr{new book{b}}
        {
            std::cout << "constructor\n";
        }
        ~bookPtr()
        {
            std::cout << "~destructor\n";
            delete bPtr;
        }
        bookPtr(const bookPtr& copy)
        {
            std::cout << "copy constructor\n";
            bPtr =copy.bPtr ? new book{*copy.bPtr}:nullptr;
        }
        bookPtr(bookPtr&& move) noexcept //예외처리에서 다시 다룸
        {
            std::cout << "move constructor\n";
            bPtr = move.bPtr;
            move.bPtr = nullptr;
        }


        bookPtr& operator=(const bookPtr& copy)
        {
            std::cout << "copy operator=\n";
            if(this != &copy)
            {
                delete bPtr;
                bPtr =copy.bPtr ? new book{*copy.bPtr}:nullptr;
            }
            return *this;
        }


        bookPtr& operator=(bookPtr&& move) noexcept
        {
            std::cout << "move operator=\n";
            if ( this != &move)
            {
                delete bPtr;
                bPtr = move.bPtr;
                move.bPtr = nullptr;
            }
            return *this;
        }


        void print()const
        {
            if (bPtr)
            std::cout << *bPtr;
        else
        std::cout << "no data (nullptr)\n";
       
        }




    };
}
