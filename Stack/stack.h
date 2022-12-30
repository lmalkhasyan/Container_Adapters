#ifndef STACK_H
#define STACK_H

#include <deque>

namespace my
{
	template<class T, class Container = std::deque<T>> 
	class stack
	{
		protected:
			Container c;
		public:
			// Typedefs
			using container_type = Container;
			using value_type = typename Container::value_type;
			using size_type =  typename Container::size_type;
			using reference = typename Container::reference;
			using const_reference = typename Container::const_reference;
			

			// Ctors
			stack() : stack(Container()) { }		// (1)
			explicit stack(const Container& cont)	// (2)
			:c(cont) { } 
			explicit stack(Container&& cont)		// (3)
			:c(std::move(cont)) { }
			stack(const stack& other)				// (4)
			:c(other.c) { }
			stack(const stack&& other)				// (5)
			:c(std::move(other.c)) { }
			template< class InputIt >				// (6)
			stack(InputIt first, InputIt last)
			:c(first, last) {}
			
			// Dtor
			~stack() = default;

			// Operator=
			stack& operator=( const stack& other )
			{
				c = other.c;
				return *this;
			}
			stack& operator=( stack&& other )
			{
				c = std::move(other.c);
				return *this;
			}

			// Member functions
			reference top()
			{
				return c.back();
			}
		
			const_reference top() const
			{
				return c.back();
			}

			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			void push(const value_type& value)
			{
				c.push_back(value);
			}
			
			void push(value_type&& value)
			{
				c.push_back(std::move(value));
			}

			template< class... Args >
			decltype(auto) emplace( Args&&... args )
			{
				reference ref = c.emplace_back(std::forward<Args>(args)...);
				return ref;
			}
			
			void pop()
			{
				c.pop_back();
			}

			void swap(stack& other)
			{
				using std::swap;
				swap(c, other.c);
			}





	};

}

#endif
