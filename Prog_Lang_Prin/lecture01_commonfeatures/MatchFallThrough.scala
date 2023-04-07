package lecture01_commonfeatures

object MatchFallThrough {
  def main(args: Array[String]): Unit = {
    var x = 20
    x match {
      case 10 | 20 | 30 | 40 | 50 => println(s"x is $x")
      case 20 | 25 | 45 | 55 => {
        println(s"x is $x")
        println("and that's it")
      }
      case _ =>
    }
  }
}
