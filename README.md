[Yaler][1] and Spark Core
--------------------

Yaler is a relay service which uses [Reverse HTTP][2] to connect to the device. Using Yaler, devices can be accessed from outside with a public URL. The URL is in the form of `<yalerid>.yaler.net`. The protocol is very simple to implement. Yaler provides difference SDK for devices to connect to the service. For this sample I took Yaler Arduino library and converted to Spark Core.

To use this sample you should have Yaler account. Yaler provides one HTTP Relay domain for free. If you want additional domains or HTTPS domain, you should pay for that. 

To use this sample first create an account and get one Yaler domain, replace the token `<<yalerid>>` in the source code with the relay domain id. Run the application, now you are connected to Yaler and can access the Spark Core with the URL `<<yalerid>>.yaler.net`.

**Screenshot**

![enter image description here][3]

  [1]: https://www.yaler.net/
  [2]: http://reversehttp.net/reverse-http-spec.html
  [3]: https://raw.githubusercontent.com/krvarma/Yaler_SparkCore/master/web.png