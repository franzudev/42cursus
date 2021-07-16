//
// Created by Federico Francois on 7/16/21.
//

#include "mutantstack.hpp"

template <typename T>
MutantStack<typename T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mutantStack) {

}
