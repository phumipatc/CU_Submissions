package lecture01_commonfeatures

object MultipleRangeLoop {
  def main(args: Array[String]): Unit = {
    for(x <- 0.until(5); i <- 0 to 4) {
      println(s"$x , $i")
    }
  }
}
