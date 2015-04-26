#! /usr/bin/env ruby
# coding: utf-8

def escape(text)
  text.gsub(/@/, "@@").gsub(/{/, "@{").gsub(/}/, "@}")
end

$:.unshift("../lib")

require "adlint"

c = AdLint::MessageCatalog.instance.load("../etc/mesg.d/ja_JP/messages.yml")

c.each do |id, text|
  puts <<EOF
@cindex #{id}
@anchor{#{id}}
@section #{id}

@subsection メッセージ本文

#{escape(text)}

@subsection 内容

追記予定。

@subsection サンプルコード

追記予定。

@subsection 関連メッセージ

追記予定。

EOF
end

exit 0
