package Banner

import scalafx.application.JFXApp
import scalafx.application.JFXApp.PrimaryStage
import scalafx.scene._
import scalafx.scene.Scene
import scalafx.scene.control.{ComboBox, Button, Label, MenuBar, Menu, MenuItem, SeparatorMenuItem, TextField, ColorPicker}
import scalafx.scene.paint.Color._
import scalafx.scene.paint._
import scalafx.scene.text.Text
import scalafx.scene.image.WritableImage
import scalafx.scene.image.Image
import scalafx.scene.Node
import scalafx.scene.layout.HBox
import scalafx.scene.effect.DropShadow
import scalafx.stage.FileChooser

import scalafx.event.ActionEvent
import scalafx.css
import scalafx.Includes._
import scalafx.geometry.Insets
import javax.imageio.ImageIO
import scalafx.embed.swing._
import scalafx.embed.swing.SwingFXUtils;
import java.awt.image.BufferedImage;
import java.io.File;

object ScalaFXBanerMaker extends JFXApp {

  stage = new PrimaryStage {
   
    
    title = "BannerMaker"
    scene = new Scene(800,600) {
      
      val menuBar = new MenuBar
      val fileMenu = new Menu("File")
     
      val saveItem = new MenuItem("Save")
        //  saveItem.onAction = (e:ActionEvent) => {
        //    val img = Box.snapshot
       //     println("DOne")
         // }
      val exitItem = new MenuItem("Exit")
          exitItem.onAction = (e:ActionEvent) => sys.exit(0)
      fileMenu.items = List(saveItem, new SeparatorMenuItem, exitItem)
      menuBar.menus = List(fileMenu)
      menuBar.prefWidth = 800
      menuBar.prefHeight = 25


      val textField = new TextField
          textField.layoutY = 26
          textField.prefWidth=149
      val apply = new Button("Apply!")
          apply.layoutY=26
          apply.layoutX=150
          apply.prefWidth = 50

      val colorpicker = new ColorPicker(Color.White)
          colorpicker.layoutY=26
          colorpicker.layoutX=201
          colorpicker.prefWidth=100

      val textFont = new TextField
          textFont.layoutY = 26
          textFont.layoutX = 302
          textFont.prefWidth=50
          textFont.text.value = "100"
      val applyFont = new Button("Ok")
          applyFont.layoutY=26
          applyFont.layoutX=353
          applyFont.prefWidth = 40

      val comboBox = new ComboBox(List("Helvetica","Arial","Verdana","Tahoma","Courier"))
          comboBox.layoutY=26
          comboBox.layoutX=394
          comboBox.promptText = "Helvetica"
      val Box = new HBox {
        padding = Insets(50, 80, 50, 80)
        children = Seq(
          new Text {
            text = "Scala FX"
            style = "-fx-font: normal bold 100pt sans-serif"
            fill = new LinearGradient(
              endX = 0,
              stops = Stops(Red, DarkRed))
          }
          
        )
      }
      apply.onAction = (e:ActionEvent) =>{
        val text = new Text {
            text = textField.text.value
            style = "-fx-font-size: "+ textFont.text.value+";" + "-fx-font-family: "+ comboBox.value.apply +";"
            fill = new LinearGradient(
              endX = 0,
              stops = Stops(Red, DarkRed))
          }
          Box.children = text
          
      }
      colorpicker.onAction = (e:ActionEvent) => {
        Box.style = "-fx-background-color: #" + (colorpicker.value.apply.toString.dropRight(2)).drop(2) + ";"
        
      }
      applyFont.onAction = (e:ActionEvent) => {
        Box.children(0).style = "-fx-font-size: "+ textFont.text.value+";" + "-fx-font-family: "+ comboBox.value.apply +";"
      }
      comboBox.onAction = (e:ActionEvent) => {
        Box.children(0).style = "-fx-font-family: "+ comboBox.value.apply +";" + "-fx-font-size: "+ textFont.text.value+";"
      }
      Box.layoutY = 51
      saveItem.onAction = (e:ActionEvent) => {
        val fileChooser = new FileChooser
        val selectedFile = fileChooser.showSaveDialog(stage)
        println(selectedFile);
      val param = new SnapshotParameters()
      val img = Box.snapshot(param, null)
      val bufferedImage = SwingFXUtils.fromFXImage(img, null)
      val file = new File(selectedFile.toString)
      println("Writing snapshot to: " + file.getAbsolutePath)
      javax.imageio.ImageIO.write(bufferedImage, "png", file)
      }
      content = List(menuBar, textField,apply,colorpicker, textFont,applyFont,Box,comboBox)
    }
    

  }
}
