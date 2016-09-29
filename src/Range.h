/******************************************************************************
 *
 * COPYRIGHT Vinicius G. Mendonca ALL RIGHTS RESERVED.
 *
 * This software cannot be copied, stored, distributed without
 * Vinicius G. Mendonca prior authorization.
 *
 * This file was made available on http://github.com/ViniGodoy and it is free
 * to be restributed or used under Creative Commons license 2.5 br:
 * http://creativecommons.org/licenses/by-sa/2.5/br/
 *
 *******************************************************************************
 * Este software nao pode ser copiado, armazenado, distribuido sem autorizacao
 * a priori de Vinicius G. Mendonca
 *
 * Este arquivo foi disponibilizado no site http://github.com/ViniGodoy e esta
 * livre para distribuicao seguindo a licenca Creative Commons 2.5 br:
 * http://creativecommons.org/licenses/by-sa/2.5/br/
 *
 ******************************************************************************/

#pragma once

#include <stdlib.h>
namespace math
{
	template <typename T>
	class Range
	{
		private:
			T from;
			T to;

		public:
			Range(T fromTo)
				: from(fromTo), to(fromTo)
			{
			}

			Range(T _from, T _to) 
				: from(_from), to(_to)	
			{
			}

			void set(T _from, T _to)
			{
				from = _from;
				to = _to;
			}

			inline void setFrom(T value) { from = value; }
			inline void setTo(T value) { to = value; }

			inline T getFrom() const { return from; }
			inline T getTo() const { return to; }

			T getMin() const { return to < from ? to : from; }
			T getMax() const { return to > from ? to : from; }

		
			T random() const
			{
				return getValue(static_cast<double>(rand()) / RAND_MAX);
			}

			inline bool isInRange(T value) const
			{
				return value >= getMin() && value <= getMax();
			}

			T getValue(double factor) const
			{
				if (to == from) return to;

				factor = factor < 0 ? 0 : (factor > 1 ? 1 : factor);			
				return static_cast<T>(intervalSign() * factor + from);
			}


			double factor(T number) const
			{
				if (to == from) return 1;

				return !isInRange(number) ? 0 : (number - from) / intervalSign();
			}

			inline double interval() const
			{
				return abs(intervalSign());
			}

			inline double intervalSign() const
			{
				return to * 1.0 - from;
			}

			template <typename V>
			float convert(V value, Range<V> range) const
			{
				return getValue(range.factor(value));
			}
	};
}
