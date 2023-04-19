package main

object question04 {
  def reverse(list: List[Any]):List[Any] = {
    if(list.isEmpty)
      return Nil
    return reverse(list.tail)++List(list.head)
  }
  def process(l1: List[Any], l2: List[Any]): Boolean = {
    if(l1.isEmpty && l2.isEmpty)
      return true
    if(l1.head != l2.head)
      return false
    return (l1.head == l2.head) && process(l1.tail,l2.tail)
  }
  def palindrome(list: List[Any]):Boolean = {
    return process(list, reverse(list))
  }
  def main(Args: Array[String]) = {
    var l1 = List()
    var l2 = List(0,1,2,3)
    var l3 = List(0,1,2,3,4)
    var l4 = List(0)
    var l5 = List(0,1,0)
    var l6 = List(1,0,0,1)
    if(palindrome(l6))
      println("True")
    else
      println("False")
  }
}
