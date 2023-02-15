/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/15 11:25:50 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <cstddef>

// std::iterator_traits
namespace ft
{
    struct random_access_iterator_tag {};
    
    /* =============================
        Start iterator class
    ===============================*/ 
    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
    
    /* =============================
        Start iterator_traits class
    ===============================*/ 
    template <class Iterator> 
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };
    template <class T> 
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };
    template <class T> 
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    /* =====================================
        Start reverse_iterator class
    =======================================*/ 
    template <class Iterator>
    class reverse_iterator : public iterator<
                        typename iterator_traits<Iterator>::iterator_category,
                        typename iterator_traits<Iterator>::value_type,
                        typename iterator_traits<Iterator>::difference_type,
                        typename iterator_traits<Iterator>::pointer,
                        typename iterator_traits<Iterator>::reference>
    {
    protected:
        Iterator current;
        
    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::reference           reference;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value_type;

    public:
        // class constructors 
        reverse_iterator(): current(){}
        explicit reverse_iterator(Iterator x) : current(x){}
        template <class U> reverse_iterator(const reverse_iterator<U>& u): current(u.base()){}
        template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u)
        {
            this->current = u.base();
            return *this;
        }

        // memeber functions
        Iterator base() const 
        {
            return this->current;
        };
        reference operator*() const 
        {
            return *(this->current - 1);
        };
        pointer   operator->() const
        {
            return &(operator*());
        };
        reverse_iterator& operator++()
        {
            --this->current;
            return *this;
        };
        reverse_iterator  operator++(int)
        {
            reverse_iterator tmp(*this);
            --this->current;
            return (tmp);
        };
        reverse_iterator& operator--()
        {
            ++this->current;
            return *this;
        };
        reverse_iterator  operator--(int)
        {
            reverse_iterator tmp(*this);
            ++this->current;
            return (tmp);
        };
        reverse_iterator  operator+ (difference_type n) const
        {
            return reverse_iterator(this->current - n);
        };
        reverse_iterator& operator+=(difference_type n)
        {
            this->current -= n;
            return *this;
        }
        reverse_iterator  operator- (difference_type n) const
        {
            return reverse_iterator(this->current + n);
        };
        reverse_iterator& operator-=(difference_type n)
        {
            this->current += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };

    template <class _Iter1, class _Iter2>
	bool operator==(const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() == _right.base());
	}
	template <class _Iter1, class _Iter2>
	bool operator!=(const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() != _right.base());
	}
	template <class _Iter1, class _Iter2>
	bool operator<=(const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() >= _right.base());
	}
	template <class _Iter1, class _Iter2>
	bool operator>=(const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() <= _right.base());
	}
	template <class _Iter1, class _Iter2>
	bool operator< (const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() > _right.base());
	}
	template <class _Iter1, class _Iter2>
	bool operator> (const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_left.base() < _right.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) 
    {
		return (rev_it + n);
	}

	template <class _Iter1, class _Iter2>
	typename reverse_iterator<_Iter1>::difference_type operator-(const reverse_iterator<_Iter1>& _left, const reverse_iterator<_Iter2>& _right) 
    {
		return (_right.base() - _left.base());
	}


    /* =====================================
        Start random_access_iterator class
    =======================================*/ 
    template <class T>
        class random_access_iterator : public iterator<random_access_iterator_tag, T>{
        public:
            typedef T                                                                                    iterator_type;
            typedef typename iterator<random_access_iterator_tag, iterator_type>::iterator_category      iterator_category;
            typedef typename iterator<random_access_iterator_tag, iterator_type>::value_type             value_type;
            typedef typename iterator<random_access_iterator_tag, iterator_type>::difference_type        difference_type;
            typedef typename iterator<random_access_iterator_tag, iterator_type>::pointer                pointer;
            typedef typename iterator<random_access_iterator_tag, iterator_type>::reference              reference;
        protected:
            pointer _p;
        public:
            // class constructors
            random_access_iterator(): _p() {}
            random_access_iterator(pointer ptr): _p(ptr) {}
            random_access_iterator(const random_access_iterator<T>& other): _p(other._p) {}
            virtual ~random_access_iterator() {}
       
            template <class Iter1> 
            random_access_iterator& operator=(const random_access_iterator<Iter1>& other)
            {
                this->_p = other.base();
                return *this;
            }

            // class functions
            pointer base(void) const {
                return (_p);
            }

            reference operator* (void)const {
                return (*_p);
                }
            pointer   operator->(void)const {
                return (&(operator*()));
            }
            reference operator[](difference_type n)const {
                return (_p[n]);
            }

            random_access_iterator operator+(difference_type n)const {
                return (_p + n);
            }
            random_access_iterator operator-(difference_type n)const {
                return (_p - n);
            }

            random_access_iterator& operator++(void) {
                ++_p;
                return (*this);
            }
            random_access_iterator operator++(int) {
                random_access_iterator tmp(*this);
                _p++;
                return (tmp);
            }
            random_access_iterator& operator--(void) {
                --_p;
                return (*this);
            }
            random_access_iterator operator--(int) {
                random_access_iterator tmp(*this);
                _p--;
                return (tmp);
            }

            random_access_iterator& operator+=(difference_type n) {
                _p += n;
                return (*this);
            }
            random_access_iterator& operator-=(difference_type n) {
                _p -= n;
                return (*this);
            }
        };

        template <typename _T1, typename _T2>
        bool operator==(const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() == _right.base());
        }
        template <typename _T1, typename _T2>
        bool operator!=(const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() != _right.base());
        }
        template <typename _T1, typename _T2>
        bool operator<=(const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() <= _right.base());
        }
        template <typename _T1, typename _T2>
        bool operator>=(const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() >= _right.base());
        }
        template <typename _T1, typename _T2>
        bool operator< (const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() < _right.base());
        }
        template <typename _T1, typename _T2>
        bool operator> (const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) 
        {
            return (_left.base() > _right.base());
        }
        template <typename _T1>
        random_access_iterator<_T1> operator+(typename random_access_iterator<_T1>::difference_type n, const random_access_iterator<_T1>& rand_it) {
            return (rand_it + n);
        }
        template <typename _T1, typename _T2>
        typename random_access_iterator<_T1>::difference_type operator-(const random_access_iterator<_T1>& _left, const random_access_iterator<_T2>& _right) {
            return (_left.base() - _right.base());
        }

}
