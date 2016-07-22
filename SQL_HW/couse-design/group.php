<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Ristorante Con Fusion</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/bootstrap-theme.min.css" rel="stylesheet">
    <link href="css/font-awesome.min.css" rel="stylesheet">
    <link href="css/bootstrap-social.css" rel="stylesheet">
    <link href="css/mystyles.css" rel="stylesheet">
</head>

<body>
    <nav class="navbar navbar-fixed-top navbar-inverse" role="navigation">
        <div class="container">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="./index.php"><i class="fa fa-futbol-o"></i> Sports</a>
            </div>
            <div id="navbar" class="navbar-collapse collapse">
                <ul class="nav navbar-nav">
                    <li><a href="./index.php">
                    <span class="glyphicon glyphicon-home" aria-hidden="true"></span> Home</a>
                    </li>
                    <li><a href="./register.html"><i class="fa fa-registered"></i> 报名</a></li>
                    <li><a href="./score.html"><i class="fa fa-pencil"></i> 登录成绩</a></li>
                    <li><a href="./publish.html"><i class="fa fa-pencil"></i> 单项成绩公布</a></li>
                    <li class="active"><a href="./group.html"><i class="fa fa-sort-amount-desc"></i> 团体总分排名</a></li>
                    <li><a href="./aboutus.html"><i class="fa fa-info-circle"></i> About</a></li>
                </ul>
            </div>
        </div>
    </nav>
    <header class="jumbotron">

        <!-- Main component for a primary marketing message or call to action -->
        <div class="container">
            <div class="row row-header">
                <div class="col-xs-12 col-sm-8">
                    <h1>第一届运动会</h1>
                    <p style="padding:40px;"></p>
                    <p>运动会管理系统</p>
                </div>
                <div class="col-xs-12 col-sm-4">
                    <p style="padding:20px;"></p>
                    <!-- <img src="img/logo.png" class="img-responsive"> -->
                    <i class="fa fa-futbol-o fa-5x"></i>
                </div>
                <!-- <div class="col-xs-12 col-sm-2">
                    <p style="padding:40px;"></p>
                    <a class="btn btn-warning" href="#">Reserve Tables</a>
                </div> -->
            </div>
        </div>
    </header>

    <div class="container">
        <div class="row row-content">
            <div class="col-xs-12">
                <h2>RANK</h2>
            </div>
            <div class="col-xs-12">
            <?php
                include 'rank.php';
            ?>
            </div>
        </div>
    </div>

    <footer class="row-footer">
        <div class="container">
            <div class="row">
                <div class="col-xs-12 col-sm-8">
                    <h5>Our Address</h5>
                    <address>
                      UJN<br>
                      Jinan<br>
                      China<br>
                      <i class="fa fa-phone"></i>: +852 1234 5678<br>
                      <i class="fa fa-fax"></i>: +852 8765 4321<br>
                      <i class="fa fa-envelope"></i>: <a href="mailto:ixuhefeng@gmail.com">ixuhefeng@gmail.com</a>
                   </address>
                </div>
                <div class="col-xs-12 col-sm-4">
                    <div style="padding: 40px 10px;">
                        <div class="nav navbar-nav" style="padding: 40px 10 px;">
                            <a class="btn btn-social-icon btn-google-plus" href="http://google.com/+"><i class="fa fa-google-plus fa-2x"></i></a>

                            <a class="btn btn-social-icon btn-facebook" href="http://www.facebook.com/profile.php?id="><i class="fa fa-facebook fa-2x"></i></a>

                            <a class="btn btn-social-icon btn-linkedin" href="http://www.linkedin.com/in/"><i class="fa fa-linkedin fa-2x"></i></a>

                            <a class="btn btn-social-icon btn-twitter" href="http://twitter.com/"><i class="fa fa-twitter fa-2x"></i></a>

                            <a class="btn btn-social-icon btn-youtube" href="http://youtube.com/"><i class="fa fa-youtube fa-2x"></i></a>

                            <a class="btn btn-social-icon" href="mailto:"><i class="fa fa-envelope-o fa-2x"></i></a>
                        </div>
                    </div>
                </div>
                <div class="col-xs-12">
                    <!-- <p style="padding:10px;"></p> -->
                    <p align=center>Made by 许和风</p>
                </div>
            </div>
        </div>
    </footer>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
</body>

</html>