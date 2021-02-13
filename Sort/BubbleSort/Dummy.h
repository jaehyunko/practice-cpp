#pragma once

namespace jh
{
	class Dummy
	{
	public:
		Dummy(int n, char c)
			: mN(n)
			, mC(c)
		{
		}

		bool operator==(const Dummy& rhs)
		{
			return (mN == rhs.mN) && (mC == rhs.mC);
		}

		bool operator<(const Dummy& rhs)
		{
			return mN < rhs.mN;
		}

		bool operator>(const Dummy& rhs)
		{
			return mN > rhs.mN;
		}

		int N() const
		{
			return mN;
		}

		char C() const
		{
			return mC;
		}
	private:
		int mN;
		char mC;
	};
}