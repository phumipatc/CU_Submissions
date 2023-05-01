package main

object testing {
  def addSpecial(x: Int, y: Int): Int => Int = {
    if(x+y <= 0)
      return z=>z+10
    else
      return z=>z-10
  }

  def main(args: Array[String]): Unit = {
    val a1 = addSpecial(1, -5)
    val a2 = addSpecial(2, 3)

    println(a1(8) == 18) // true
    println(a2(13) == 3) //true
    println(a2(7) == -3) //true
    println(a1(-10) == 0) //true
  }
}
