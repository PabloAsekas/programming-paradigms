-- Pablo Bermejo
-- https://github.com/PabloAsekas/

module Principal where

import Data.Char
import Pila
import InfijaAPostfija
import ResolverPostfija
import Utilidades

main :: IO ()
main = do
	print "Inserta el nombre del archivo con la entrada del programa y la extension sin comillas por favor"
	print "Insert the name of the file with the program input with the extension and without quotation marks, please"
	archivo <- getLine
	texto <- readFile archivo --leemos el archivo
	--comento la funcion de impresion por si quieres ver en algún momento la salida de las variables
	--print texto
	let lineas = separarLineas texto --Separamos las operaciones unas de otras
	--print lineas
	let operaciones = separarCaracteres lineas --Separamos cada operacion en caracacteres individuales
	--print operacion
	let postfija = deInfijaAPostFija operaciones --Convertimos de infica a postfija
	--print postfija
	let postfijastring = postfijaAString postfija --Convertimos todas las operaciones postfijas a string
	--print postfijastring
	let resultados = postfijaResultado postfija --Guardamos los resultados de operar las operaciones postfijas
	--print resultados
	writeFile "intermedio.txt" $ unlines postfijastring --Guardamos las operaciones postfijas en el archivo "intermedio.txt"
	let salida = mezclarDatos lineas resultados --Mezclamos las operaciones infijas con el resultado de operar postfijas
	--print salida
	writeFile "salida.txt" $ unlines salida --Guardamos la salida en el archivo "salida.txt"
	print "Done"