#include "pch.h"
#include "CppUnitTest.h"
#include "../WalletApp/Wallet.h"
#include "../WalletApp/Wallet.cpp"
#include <stdexcept>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WalletAppTests
{
	TEST_CLASS(WalletTests)
	{
	public:

		TEST_METHOD(Deposit_NormalAmount_ReturnsNewBalance)
		{
			double res = deposit(1000.0, 500.0);
			Assert::AreEqual(1500.0, res, 0.0001);
		}

		TEST_METHOD(Deposit_ZeroAmount_ThrowsException)
		{
			Assert::ExpectException<std::invalid_argument>([] { deposit(1000.0, 0.0); });
		}

		TEST_METHOD(Deposit_NegativeAmount_ThrowsException)
		{
			Assert::ExpectException<std::invalid_argument>([] { deposit(1000.0, -200.0); });
		}

		TEST_METHOD(Withdraw_ValidAmount_ReturnsRemainder)
		{
			double res = withdraw(1000.0, 300.0);
			Assert::AreEqual(700.0, res, 0.0001);
		}

		TEST_METHOD(Withdraw_FullBalance_ReturnsZero)
		{
			double res = withdraw(1000.0, 1000.0);
			Assert::AreEqual(0.0, res, 0.0001);
		}

		TEST_METHOD(Withdraw_ExceedsBalance_ThrowsException)
		{
			Assert::ExpectException<std::invalid_argument>([] { withdraw(1000.0, 1500.0); });
		}

		TEST_METHOD(CalcPercent_ValidRate_ReturnsPercent)
		{
			double res = calcPercent(2000.0, 0.05);
			Assert::AreEqual(100.0, res, 0.0001);
		}

		TEST_METHOD(CalcPercent_ZeroBalance_ReturnsZero)
		{
			double res = calcPercent(0.0, 0.1);
			Assert::AreEqual(0.0, res, 0.0001);
		}

		TEST_METHOD(CalcPercent_Overflow_ReturnsInf)
		{
			double res = calcPercent(1e308, 10.0);
			Assert::IsTrue(std::isinf(res));
		}

		TEST_METHOD(GetAvgCheck_PeriodicFraction_MatchesWithEps)
		{
			double res = getAvgCheck(10.0, 3);
			Assert::AreEqual(3.333333, res, 1e-5);
		}

		TEST_METHOD(GetAvgCheck_ZeroCount_ThrowsException)
		{
			Assert::ExpectException<std::invalid_argument>([] { getAvgCheck(500.0, 0); });
		}
	};
}