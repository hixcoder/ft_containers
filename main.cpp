/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:04:17 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/20 16:26:02 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"


class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};
int main()
{
    // ==> algorithm tests:
    // equalTest();
    // lexicographical_compareTest();
    // is_integralTest();
    // pairTest();
    // make_pairTest();
    // enable_ifTest();
    
    // ==> iterators tests:
    // iterator_traitsTest();

    // stack tests:
    // stackTest();

    // vector tests
    // vectorTest();
// int _ratio = 10;
// std::cout << "\nstd result\n";
// {
// 	std::vector<int> v;
// 	std::vector<int> vector;
//     std::vector<int> tmp;
//     tmp.assign(2600 * _ratio, 1);
//     vector.assign(4200 * _ratio, 1);
//     vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     std::vector<A> vv;
//     std::vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }
    
//     for (size_t i = 0; i < v.size(); i++)
//         std::cout << v[i] << " ";    
// }

std::cout << "\n\nft result\n";
{
	std::vector<int> v;
	ft::vector<int> vector;
    ft::vector<int> tmp;
    // tmp.assign(2600 * _ratio, 1);
    // vector.assign(4200 * _ratio, 1);
    // vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    // v.push_back(vector[3]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }
    
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " "; 
    std::cout << "\n";
}

   
}

