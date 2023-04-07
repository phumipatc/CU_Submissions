package lecture01_commonfeatures

object MatchStatement {
  def main(args: Array[String]): Unit = {
    var x = 10
    x match {
      case 10 => println("x is 10")
      case 20 => println("x is 20")
      case 25 => {
        println("x is 25")
        println("and that's it")
      }
      case 30 => println("x is 30")
      case _ =>
    }
  }
}
