//
//  ViewController2.swift
//  WISIELEC
//
//  Created by Szymon Nowak on 13.10.2016.
//  Copyright © 2016 Kablociag Syrek i spolka. All rights reserved.
//

import UIKit

//var zwierzeta : [String] = [""]
var slowo : String = ""
var array_slowo : Array = [""]
var podkreslenia : String = ""
var new_slowo : [Character] = []


extension Array {
    mutating func shuffle() {
        if count < 2 { return }
        for i in 0..<(count - 1) {
            let j = Int(arc4random_uniform(UInt32(count - i))) + i
            guard i != j else { continue }
            swap(&self[i], &self[j])
        }
    }
}


class ViewController2: UIViewController, UITextFieldDelegate {

    var kat:String = ""
    var podkat:String = ""
    
     var zwierzeta = ["lis","krokodyl","gżegżułka","kormoran","wonsz rzeczny"]
    var rosliny = ["koniczyna","marihuanen","pszenica","lucerna"]
    var piwo = ["kasztelan","żywiec","kuflowe mocne","okocim","ciechan"]
    var wodka = ["finlandia","żołądkowa gorzka","kurwica"]
    var szczyty = ["rysy","czomolungma","świnica","kościelec"]
    var pasma = ["bieszczady","beskidy","karpaty","tatry","góry sowie"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print(kat + " " + podkat);
        Haslo.becomeFirstResponder()
        Haslo.delegate=self
        // Do any additional setup after loading the view.
        if(podkat=="Zwierzęta"){
            zwierzeta.shuffle()
            slowo=zwierzeta[0]
        }
        else if(podkat=="Rośliny"){
            rosliny.shuffle()
            slowo = rosliny[0]
        }
        else if(podkat=="Piwo"){
            piwo.shuffle()
            slowo = piwo[0]
        }
        else if(podkat=="Wódka"){
            wodka.shuffle()
            slowo = wodka[0]
        }
        else if(podkat=="Szczyty"){
            szczyty.shuffle()
            slowo = szczyty[0]
        }
        else if(podkat=="Pasma"){
            pasma.shuffle()
            slowo = pasma[0]
        }
       new_slowo = Array(slowo.characters)
        
       // print(Array("hugui".characters))
        print(new_slowo[0])
        print(new_slowo.count)
        podkreslenia=""
        for i in 0..<new_slowo.count{
            podkreslenia=podkreslenia + "_" + " "
                   }
        
        label_slowo.text=podkreslenia
       
        
    }
@IBOutlet weak var label_slowo: UILabel!
@IBOutlet weak var Haslo: UITextField!
    let limitLength = 1
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        guard let text = textField.text else { return true }
        let newLength = text.characters.count + string.characters.count - range.length
        return newLength <= limitLength
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
       // self.view.endEditing(true)
        for i in 0..<new_slowo.count{
            print(new_slowo[i])
            if(Character(Haslo.text!) == new_slowo[i]){
                print("Znaleziono dopasowanie")
             var label = label_slowo.text
              var label1 = Array(label!.characters)
                if(i==0){
                    label1[i] = new_slowo[i]}
                else{
                label1[i*2] = new_slowo[i]}
                
              label_slowo.text = String(label1)
            }
        }
        Haslo.text=""
        return false
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
        
    }
    
    
    
   
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
