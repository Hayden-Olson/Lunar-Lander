/*************************************************************
 * Module
 *      TEST WALLET
 * Description:
 *      Unit tests for the WALLET class 
 * Author:
 *      Br. Helfrich
 **************************************************************/

#pragma once

#include "wallet.h"
#include "unitTest.h"

/************************************
 * TEST WALLET
 ************************************/
class TestWallet : public UnitTest
{
public:
   void run()
   {
      reset();

      // constructor
      test_constructor_default();

      // getters
      test_getSam_zero();
      test_getSam_ten();
      test_getSue_zero();
      test_getSue_twenty();
      test_getCurrent_sam();
      test_getCurrent_sue();

      // setters
      test_updateSam_zero();
      test_updateSam_initial();
      test_updateSam_addsome();
      test_updateSue_zero();
      test_updateSue_initial();
      test_updateSue_addsome();
      test_updateCurrent_sam();
      test_updateCurrent_sue();
      test_chooseSam();
      test_chooseSue();
      test_chooseCurrent_sam();
      test_chooseCurrent_sue();

      report("Wallet");
   }
private:
   
   /***************************************
    * CONSTRUCTOR
    ***************************************/

   // default constructor
   void test_constructor_default()
   {  // setup
      // exercise
      Wallet w;
      // verify
      assertCondition(w.accountSam == 0.00);
      assertCondition(w.accountSue == 0.00);
      assertCondition(w.pCurrentAccount == &w.accountSam);
   }  // teardown

   /***************************************
    * GETTERS
    ***************************************/

    // get sam with $0.00
   void test_getSam_zero()
   {  // setup
      Wallet w;
      w.accountSam = 0.00;
      w.accountSue = 99.99;
      w.pCurrentAccount = (double *)0xbadf00d1;
      double result = -1.00;
      // exercise
      result = w.getSam();
      // verify
      assertCondition(result == 0.00);
      assertCondition(w.accountSam == 0.00);
      assertCondition(w.accountSue == 99.99);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

    // get sam with $10.00
   void test_getSam_ten()
   {  // setup
      Wallet w;
      w.accountSam = 10.00;
      w.accountSue = 88.88;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double result = -1.00;
      // exercise
      result = w.getSam();
      // verify
      assertCondition(result == 10.00);
      assertCondition(w.accountSam == 10.00);
      assertCondition(w.accountSue == 88.88);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

    // get sam with $0.00
   void test_getSue_zero()
   {  // setup
      Wallet w;
      w.accountSam = 7.77;
      w.accountSue = 0.00;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double result = -1.00;
      // exercise
      result = w.getSue();
      // verify
      assertCondition(result == 0.00);
      assertCondition(w.accountSam == 7.77);
      assertCondition(w.accountSue == 0.00);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // get sue with $20.00
   void test_getSue_twenty()
   {  // setup
      Wallet w;
      w.accountSam = 6.66;
      w.accountSue = 20.00;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double result = -1.00;
      // exercise
      result = w.getSue();
      // verify
      assertCondition(result == 20.00);
      assertCondition(w.accountSam == 6.66);
      assertCondition(w.accountSue == 20.00);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // get current (sam) with $11.11
   void test_getCurrent_sam()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = &w.accountSam;
      double result = -1.00;
      // exercise
      result = w.getCurrent();
      // verify
      assertCondition(result == 11.11);
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSam);
   }  // teardown

   // get current (sue) with $22.22
   void test_getCurrent_sue()
   {  // setup
      Wallet w;
      w.accountSam = 33.33;
      w.accountSue = 22.22;
      w.pCurrentAccount = &w.accountSue;
      double result = -1.00;
      // exercise
      result = w.getCurrent();
      // verify
      assertCondition(result == 22.22);
      assertCondition(w.accountSam == 33.33);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSue);
   }  // teardown

   /***************************************
    * SETTERS
    ***************************************/

   // update sam from $0.00 to $0.00
   void test_updateSam_zero()
   {  // setup
      Wallet w;
      w.accountSam = 0.00;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 0.00;
      // exercise
      w.updateSam(amount);
      // verify
      assertCondition(amount == 0.00);
      assertCondition(w.accountSam == 0.00);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update sam from $0.00 to $11.11
   void test_updateSam_initial()
   {  // setup
      Wallet w;
      w.accountSam = 0.00;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 11.11;
      // exercise
      w.updateSam(amount);
      // verify
      assertCondition(amount == 11.11);
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update sam from $11.11 -> 44.44
   void test_updateSam_addsome()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 33.33;
      // exercise
      w.updateSam(amount);
      // verify
      assertCondition(amount == 33.33);
      assertCondition(w.accountSam == 44.44);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update sue from $0.00 to $0.00
   void test_updateSue_zero()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 0.00;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 0.00;
      // exercise
      w.updateSue(amount);
      // verify
      assertCondition(amount == 0.00);
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 0.00);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update sue from $0.00 to $22.22
   void test_updateSue_initial()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 0.00;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 22.22;
      // exercise
      w.updateSue(amount);
      // verify
      assertCondition(amount == 22.22);
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update sue from $22.22 -> 55.55
   void test_updateSue_addsome()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d1;
      double amount = 33.33;
      // exercise
      w.updateSue(amount);
      // verify
      assertCondition(amount == 33.33);
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 55.55);
      assertCondition(w.pCurrentAccount == (double*)0xbadf00d1);
   }  // teardown

   // update current, which is ssam
   void test_updateCurrent_sam()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = &w.accountSam;
      double amount = 33.33;
      // exercise
      w.updateCurrent(amount);
      // verify
      assertCondition(amount == 33.33);
      assertCondition(w.accountSam == 44.44);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSam);
   }  // teardown

   // update currents, which is sue
   void test_updateCurrent_sue()
   {  // setup
      Wallet w;
      w.accountSam = 44.44;
      w.accountSue = 22.22;
      w.pCurrentAccount = &w.accountSue;
      double amount = 33.33;
      // exercise
      w.updateCurrent(amount);
      // verify
      assertCondition(amount == 33.33);
      assertCondition(w.accountSam == 44.44);
      assertCondition(w.accountSue == 55.55);
      assertCondition(w.pCurrentAccount == &w.accountSue);
   }  // teardown

   // make sam the current
   void test_chooseSam()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d;
      // exercise
      w.chooseSam();
      // verify
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSam);
   }  // teardown

   // make sue the current
   void test_chooseSue()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d;
      // exercise
      w.chooseSue();
      // verify
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSue);
   }  // teardown

   // make sam the current
   void test_chooseCurrent_sam()
   {  // setup
      Wallet w;
      w.accountSam = 111.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d;
      // exercise
      w.chooseCurrent();
      // verify
      assertCondition(w.accountSam == 111.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSam);
   }  // teardown

   // make sue the current
   void test_chooseCurrent_sue()
   {  // setup
      Wallet w;
      w.accountSam = 11.11;
      w.accountSue = 22.22;
      w.pCurrentAccount = (double*)0xbadf00d;
      // exercise
      w.chooseCurrent();
      // verify
      assertCondition(w.accountSam == 11.11);
      assertCondition(w.accountSue == 22.22);
      assertCondition(w.pCurrentAccount == &w.accountSue);
   }  // teardown

};