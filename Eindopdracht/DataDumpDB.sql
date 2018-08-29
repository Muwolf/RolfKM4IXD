-- phpMyAdmin SQL Dump
-- version 4.0.10.20
-- https://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 13, 2018 at 07:48 PM
-- Server version: 5.7.17
-- PHP Version: 5.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `rolfjurgens`
--

-- --------------------------------------------------------

--
-- Table structure for table `calender`
--

CREATE TABLE IF NOT EXISTS `calender` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` datetime NOT NULL,
  `location_id` int(11) NOT NULL,
  `what` varchar(64) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=24 ;

--
-- Dumping data for table `calender`
--

INSERT INTO `calender` (`id`, `date`, `location_id`, `what`) VALUES
(1, '2018-06-04 11:45:00', 1, 'Kernmodule'),
(2, '2018-06-06 19:00:00', 3, 'D&D'),
(3, '2018-06-05 10:00:00', 1, 'ProjectWerk'),
(4, '2018-06-06 10:00:00', 1, 'Projectwerk'),
(5, '2018-06-07 10:00:00', 1, 'Projectwerk'),
(6, '2018-06-11 10:00:00', 1, 'Projectwerk'),
(7, '2018-06-12 10:00:00', 1, 'Projectwerk'),
(8, '2018-06-13 10:00:00', 1, 'Projectwerk'),
(9, '2018-06-14 10:00:00', 1, 'Projectwerk'),
(10, '2018-06-14 10:00:00', 1, 'Projectwerk'),
(11, '2018-06-09 10:00:00', 3, 'Huiswerk'),
(12, '2018-06-08 19:00:00', 1, 'Test'),
(14, '2018-06-10 00:30:00', 3, 'test'),
(16, '2018-06-14 09:15:00', 1, 'Postmortem Kernmodule'),
(17, '2018-06-12 19:00:00', 3, 'D&D'),
(18, '2018-06-14 09:35:00', 1, 'postmortem kernmodule deel 2'),
(19, '2018-06-14 09:55:00', 1, 'postmortem kernmodule deel 3'),
(20, '2018-06-14 10:15:00', 1, 'postmortem kernmodule deel 4'),
(21, '2018-06-14 10:35:00', 1, 'postmortem kernmodule deel 5'),
(22, '2018-06-14 10:55:00', 1, 'postmortem kernmodule deel 6'),
(23, '2018-06-13 13:10:00', 3, 'ditiseentest');

-- --------------------------------------------------------

--
-- Table structure for table `data`
--

CREATE TABLE IF NOT EXISTS `data` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `thing_id` int(11) NOT NULL,
  `time` datetime NOT NULL,
  `temp` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `data`
--

INSERT INTO `data` (`id`, `thing_id`, `time`, `temp`) VALUES
(1, 4, '2018-05-14 00:00:00', 28),
(2, 4, '2018-05-14 00:00:00', 28),
(3, 4, '2018-05-14 00:00:00', 28),
(4, 4, '2018-05-14 00:00:00', 29),
(5, 4, '2018-05-14 00:00:00', 29),
(6, 4, '2018-05-14 00:00:00', 29),
(7, 4, '2018-05-14 00:00:00', 29),
(8, 4, '2018-05-14 00:00:00', 29),
(9, 4, '2018-05-14 14:25:03', 29),
(10, 4, '2018-05-14 14:30:21', 29),
(11, 4, '2018-05-14 14:37:33', 53),
(12, 4, '2018-05-14 14:39:57', 53),
(13, 1, '2018-06-20 23:34:00', 32),
(14, 1, '2018-06-20 23:34:00', 18),
(15, 1, '2018-06-20 23:34:00', 23);

-- --------------------------------------------------------

--
-- Table structure for table `leavingTime`
--

CREATE TABLE IF NOT EXISTS `leavingTime` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `location_id` int(11) NOT NULL,
  `time_past` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `locationID` (`location_id`),
  KEY `locationID_2` (`location_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=83 ;

--
-- Dumping data for table `leavingTime`
--

INSERT INTO `leavingTime` (`id`, `location_id`, `time_past`) VALUES
(1, 1, 500),
(2, 1, 1000),
(3, 1, 500),
(4, 2, 120),
(5, 2, 800),
(6, 2, 150),
(7, 3, -120),
(8, 2, 10000),
(9, 3, -91210),
(10, 3, -600),
(11, 4, 200),
(12, 4, 120),
(13, 4, 1020),
(14, 1, 120),
(15, 1, 500),
(16, 1, 500),
(17, 1, 501),
(74, 1, 1000),
(78, 1, -8681),
(79, 1, -6167),
(80, 1, -6095),
(81, 3, -485),
(82, 3, -461);

-- --------------------------------------------------------

--
-- Table structure for table `location`
--

CREATE TABLE IF NOT EXISTS `location` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL,
  `travel_time` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `location`
--

INSERT INTO `location` (`id`, `name`, `travel_time`) VALUES
(1, 'HKU locatie IBB', 1200),
(2, 'HKU locatie Nieuwe Kade', 420),
(3, 'Thuis', 0),
(4, 'Station', 900);

-- --------------------------------------------------------

--
-- Table structure for table `things`
--

CREATE TABLE IF NOT EXISTS `things` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `name` varchar(50) NOT NULL,
  `location` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Dumping data for table `things`
--

INSERT INTO `things` (`id`, `user_id`, `name`, `location`) VALUES
(1, 1, 'Huiskamer', 'Huiskamer'),
(2, 1, 'Keuken', 'Keuken'),
(3, 1, 'Tuin', 'Achtertuin'),
(4, 2, 'Slaapkamerraam', 'Slaapkamer'),
(5, 2, 'Huiskamer', 'huiskamer'),
(6, 2, 'Wasmachine', 'Bijkeuken'),
(7, 3, 'PC', 'Kantoor'),
(8, 3, 'Huiskamer', 'Huiskamer'),
(9, 3, 'Zolder', 'Zolder'),
(10, 4, 'Huiskamer', 'Huiskamer'),
(11, 4, 'Buiten', 'Dak'),
(12, 4, 'slaapkamer', 'slaapkamer'),
(13, 5, 'Huiskamer', 'Huiskamer'),
(14, 5, 'Douche', 'badkamer'),
(15, 5, 'PC', 'zolder');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `password` varchar(36) NOT NULL,
  `geboortedatum` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `geboortedatum`) VALUES
(1, 'rolf.jurgens@student.hku.nl', 'wachtwoord', '1988-04-23'),
(2, 'muwolf@gmail.com', 'wachtwoord', '1988-04-23'),
(3, 'rolf@rolfjurgens.nl', 'wachtwoord', '1988-04-23'),
(4, 'astrid@gmail.com', 'wachtwoord', '1988-08-12'),
(5, 'wessel@gmail.com', 'wachtwoord', '1992-06-12'),
(6, 'Rolf', 'wachtwoord', '1988-04-23');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
