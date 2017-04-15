type client;

type message;

type user;

type channel;

external createClient : unit => client = "Client" [@@bs.module "discord.js"] [@@bs.new];

external login : client => string => unit = "" [@@bs.send];

external onReady : client => _ [@bs.as "ready"] => (unit => unit) => unit = "on" [@@bs.send];

external onMessage : client => _ [@bs.as "message"] => (message => unit) => unit =
  "on" [@@bs.send];

external getContent : message => string = "content" [@@bs.get];

external getChannel : message => channel = "channel" [@@bs.get];

external getType : channel => string = "type" [@@bs.get];

external getAuthor : message => option user =
  "author" [@@bs.get] [@@bs.return null_undefined_to_opt];

external isBot : user => bool = "bot" [@@bs.get];

external reply : message => string => unit = "" [@@bs.send];
