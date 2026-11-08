#include "bookPtr.h"
#include <memory>


int main(){


    using namespace SeowonLim2348078;
    bookPtr bp1;
    bookPtr bp2{bp1}; //copy constructor
    bookPtr bp3{std::move(bp2)}; //move constructor
    // bp3;
    // bp3 = bp1;
    bp2 = std::move(bp3); //move operator=
    bp3 = bp2; //copy operator=


    bookPtr* bp{new bookPtr};
   


    std::unique_ptr<bookPtr> up1; //위 세줄이랑 동일하게 포인트 객체 선언, 근데 유니크
    auto up2{std::make_unique<bookPtr>(book{"title", 1, 10000})}; //얘는 delete up2; 하면 안됨


    up1 = std::move(up2);
    up1->print();


    auto sp1{std::make_shared<bookPtr>(book{"shared", 2, 20000})};
    std::shared_ptr<bookPtr> sp2{sp1};
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl; //2 2
    std::weak_ptr<bookPtr> wp1{sp1};
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl; //2 2
    sp1.reset();
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl; //0 1
    if (!wp1.expired()) sp1=wp1.lock(); //sp1 sp1 가리키는게 다시 같아짐
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl; //2 2
   
   


    delete bp; //안하면 메모리 누수
    return 0;
}
