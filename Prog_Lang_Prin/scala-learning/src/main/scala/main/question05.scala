package main

import jdk.javadoc.internal.tool.Start

object question05 {
  def merge(l1: List[Int], l2: List[Int]): List[Int] = {
    if(l1.isEmpty)
      return l2
    if(l2.isEmpty)
      return l1
    if(l1.head <= l2.head)
      return l1.head::merge(l1.tail,l2)
    else
      return l2.head::merge(l1,l2.tail)
  }
  def divide(start:Int , number:Int , list: List[Int]):List[Int] = {
    if(start == 0){
      if(number == 0)
        return Nil
      return list.head::divide(start,number-1,list.tail)
    }else {
      return divide(start - 1, number, list.tail)
    }
  }
  def mergesort(list: List[Int]):List[Int] = {
    if(list.length <= 1)
      return list
    var n = list.length/2
    var leftSide = divide(0,n,list)
    var rightSide = divide(n,list.length-n,list)
    var sortedLeft = mergesort(leftSide)
    var sortedRight = mergesort(rightSide)
    return merge(sortedLeft,sortedRight)
  }
  def main(Args:Array[String]) = {
    var l1 = List(1, 5, 8, 4, 9, 3, 6, 0, 4, 6, 3, 0, 7, 9, 4)
    var l2 = List(0, 0, 1, 3, 3, 4, 4, 4, 5, 6, 6, 7, 8, 9, 9)
    println(mergesort(l1))
  }
}
