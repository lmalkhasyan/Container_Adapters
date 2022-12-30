#ifndef STACK_H
#define STACK_H

#include <deque>

namespace my
{
	template<class T, class Container = std::deque<T>> 
	class queue
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
			queue() : queue(Container()) { }		// (1)
			explicit queue(const Container& cont)	// (2)
			:c(cont) { } 
			explicit queue(Container&& cont)		// (3)
			:c(std::move(cont)) { }
			queue(const queue& other)				// (4)
			:c(other.c) { }
			queue(const queue&& other)				// (5)
			:c(std::move(other.c)) { }
			template<class InputIt>					// (6)
			queue(InputIt first, InputIt last)
			:c(first, last) {}
			
			// Dtor
			~queue() = default;

			// Operator=
			queue& operator=( const queue& other )
			{
				c = other.c;
				return *this;
			}
			queue& operator=( queue&& other )
			{
				c = std::move(other.c);
				return *this;
			}

			// Member functions
			reference front()
			{
				return c.front();
			}
			const_reference front() const
			{
				return c.front();
			}

			reference back()
			{
				return c.back();
			}
			const_reference back() const
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
				c.pop_front();
			}

			void swap(queue& other)
			{
				using std::swap;
				swap(c, other.c);
			}
	};
}

#endif
