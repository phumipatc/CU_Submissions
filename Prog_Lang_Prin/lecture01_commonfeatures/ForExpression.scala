package lecture01_commonfeatures

object ForExpression {
  def main(args: Array[String]): Unit = {
    var r1 = for{x <- 0 until 5; if x%2==0} yield {
      println(" +++++++++++++++++++++")
      x
    }
    println(r1)
    println("-------------------")
    var mylist = List(1,3,5,7)
    var r2 = for{m <- mylist; if m >= 3 } yield {
      m
    }
    println(r2)
  }
}
