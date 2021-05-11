﻿using System;
using System.IO;
using System.Text;
using System.Timers;
/*
Todo: com고치기	
0. 평일은:이제 office컴 연결시만,즉 근무시간에만 coding작업할것
    * 근무시간(backup drive먼저) 또는 매일 1회(3회맥스)->1/19 => 기타 
    * 초과했을때 1/3 => TARGET_MAX도 늘리고..
	* 멈췄을때 1/13 => randomStopMax도 늘리고..
	5/1토에 bat file실행도 위험한거같으니 무조건 gc로 실행!
1   전날 사고발생하면 훗날은 사고없이 exe만 기도
    하루 exe했으면 그다음날 exe update없이? 얼마나 commit일어나는지 보자(일일 commit개수 줄여보기)
    1-1 1/9-> 암것도안함(이것도테스트필요)
    1-2 기능향상:         	    
        *   TARGET_MAX가 round시 1분씩 증가하는것은 어떨까? 출력시도 보내기
        *   출력멈춤현상, bat(exe+ cmd이거 안되면) 이것도 문제 생김
			일단 cmd열고 수동으로 gc실행하면서 
           => 출력멈춤현상(일단매번 cmd여는걸로)-> 제자리 출력? <- 한번더 멈춘현상발생시)
		   => exe로 바로 실행준비하자(장기plan)
        매번:   
                - 작업시간 체크
                - 수도추가: 이제 플밍 자주안하니 거의 매번 넣어야할듯
                - TARGET_MAX도 1은 늘리고~
        최근시작하나만보기 =>  이하는 1개만 더 사람답게 깔끔하게?                
                new스페인어 숫자12까지() 다음숫자없으면 확률 늘리기 :)=> log에 round도 추가?                
                else => postfix추가
                0 round에서는 round없이 command를 cero 또는 git reset으로 표기!, <= 0.와 "."도 추가!                
                - eugene 일때 -> command ,e.g. rewrite, or sPrefix(new) 추가?
                - 시간은 issue # number화 jira, bugzilla
        후순위
		    *하루7commit이하(2회이상) or 종료놓칠때?? 종료시 EMAIL?  -> later하루에 1-2개씩 commit일때만 email?
        필요여부 미지수:		
            * 안중요=> ini file, ini file 숫자증가만? 		    
            * exe check필요할듯 -exe빠지는경우 있음 update표시?    
    1-3 -release note 필요할때 무조건
        -코드정리 => 이후 build할것 !

    1-4 git 정리 + 하기전에 숫자바꾸고 저장함? 1/8할차례(기능안까먹는 용도)
        아니면 or ^B
        웬만하면 새 git이 하나로되게해보자~
        git rebase HEAD~17 -i
        git push --force(이것도됨)
        git push origin master --force(필요?)

        remote컴에서는 git reset HEAD~1 --hard로 후퇴한후 다시 git pull한다
        또는 gitk에서 hard로
        rebase하는 명령어찾기		
        https://superuser.com/questions/273172/how-do-i-reset-master-to-origin-master

2 이건 studio열지않고, 다른 application?(
    quiz 맞은거 random숫자조정으로 잘안나오게!->정치or투자)
    미린 엑셀 -> javascript?
*/

namespace gitA
{
    class Program
    {
        static readonly bool debuggingMode = false;          // true false if real mode    
        // 읽어올 text file 의 경로를 지정 합니다
        static readonly string  fileGit        = "eukm.log";
        static readonly float    WORK          = 975 / 60 / 7;   //days 420이 1일
        static          int     randomStopMax = 19;
        static readonly int     roundMax      = 21;             //같은숫자로?
        static          int     tick          = 22;             //초에 한번씩 찍기

        // 목표 일일 commit개수 줄여보기 -> 같으면 성공,
        //실패시4분씩 증가면 괜찮은듯 
        //성공 및 한화면안차면 1++
        static int     TARGET_MAX    = 7 * 60 + 34;

        // global
        static int round = 0;
        // timer 2개 
        static readonly Timer timerTick = new System.Timers.Timer();
        static System.Threading.Timer myTimer = null;          

        static void Main(string[] args)
        {                        
            if (debuggingMode)
            {
                randomStopMax = 1;
                tick = 1; //초에 한번씩 찍기
                TARGET_MAX = 1;// for test        
            } //debugging mode

            //var info = new FileInfo(fileGit);
            //if (info.LastWriteTime.Day != DateTime.Now.Day 
            // Console.WriteLine("하루지나!"); force모드 생겨 딱히 필요없을듯
            /*
            int argsCount = args.Length;
            if (argsCount >= 1)
            {
                string inputFile = args[0];
                Console.WriteLine("Force Mode: {0}", inputFile);
                Update();
            } 
            */
            RunGit();
            
            Console.WriteLine("Press Enter to exit");

            timerTick.Interval = 1000 * tick; // 단위 milisec라서
            timerTick.Elapsed += new ElapsedEventHandler(Timer_Tick);            
            timerTick.Start();
            Timer_Tick(null, null);

            Console.ReadLine();
        }
        static void RunGit()
        {
            Console.WriteLine("준비! Round {0} try--------------------------------", round);
            Random random = new Random();
            int i; //for random index

            string sLocation = "";
            string sMingling = "";
            //1 home mode확인 as sLocation
            makeTexts(ref sLocation);

            //2 Command 만들기-절반은 패스(공백)            
            if (0 == random.Next(0, 2))
            {
                string[] mingling
                    = new string[] {"", "eugene", "app", "Command", "Squash", "Update", "Commit", "commits", "push" };
                i = random.Next(0, mingling.Length);
                if (0 == random.Next(0, 2))
                    sMingling = mingling[i] + " ";
                else
                    sMingling = "new " + mingling[i] + " ";
                //postfix?//".",, "-"
            }

            //3.조사 만들기-절반은 패스(공백)
            string sPrefix = "";
            i = random.Next(0, 2);
            Console.WriteLine("sCong {0}", i);
            if (0 == i)
            {
                string[] cong = new string[] { "by", "from", "in" };
                i = random.Next(0, cong.Length);
                sPrefix = cong[i] + " ";
            }

            //4.국가 만들기
            string[] capital = new string[]
            {
                "Nigeria","Abuja","Kazakhstan","Nur Sultan","Slovakia","Bratislava","Puerto Rico","San Juan",
                "Dominican Republic","Santo Domingo","Guatemala","Guatemala City","Myanmar","Naypyidaw",
                "Ivory Coast","Yamoussoukro","Angola","Luanda","Tanzania","Dodoma","Croatia","Zagreb",
                "Lithuania","Vilnius","Uzbekistan","Tashkent","Costa Rica","San Jose","Slovenia","Ljubljana",
                "Turkmenistan","Ashgabat","Cameroon","Yaounde", "Tunisia", "Tunis","Uganda","Kampala","Latvia","Riga",
                "Zimbabwe","Harare", "Haiti", "Port-au-Prince","Bosnia and Herzegovina","Sarajevo","Mali","Bamako",
                "Zambia","Lusaka","Burkina Faso","Ouagadougou","Botswana","Gaborone"
            };
            i = random.Next(0, capital.Length);
            string sCapital = capital[i] + " ";
            string sAnswer;
            if (i % 2 == 0)
                sAnswer = capital[i + 1];
            else
                sAnswer = capital[i - 1];

            //5. round
            string sRound = "";
            if (round == 0)
            {
                string[] cero = new string[] { "git reset ", "cero ", "0 " };
                i = random.Next(0, cero.Length);
                //sRound = cero[i];
                sMingling = cero[i];
            }
            else
            {
                if (0 != random.Next(0, 3))
                {
                    if (round == 1)
                        sRound = "Uno ";
                    else if (round == 2)
                        sRound = "Dos ";
                    else if (round == 3)
                        sRound = "Tres ";
                    else if (round == 4)
                        sRound = "Cuatro ";
                    else if (round == 5)
                        sRound = "Cinco ";
                    else if (round == 6)
                        sRound = "seis ";
                    else if (round == 7)
                        sRound = "siete ";
                    else if (round == 8)
                        sRound = "ocho ";                    
                    else
                        sRound = Convert.ToString(round) + ".";
                    //모두 소문자화            
                    sRound = sRound.ToLower();
                }
            }
            //~

            // 6.random Target with ticket 
            DateTime now = DateTime.Now;
            string sTime = now.ToString("HH:mm");

            int thisRoundTarget = TARGET_MAX + round;
            int randomResult = random.Next(1, thisRoundTarget);
            DateTime targetTime = now.AddMinutes(randomResult);
            string sTarget = targetTime.ToString("HH:mm");
            string sTargetHour4Commit = targetTime.Hour.ToString();

            i = random.Next(0, 2);
            Console.WriteLine("sTargetHour4Commit {0}", i);
            if (0 == i)
            {
                sTargetHour4Commit = "ticket" + sTargetHour4Commit;
            }

            //우선 매번~
            if (sLocation == "")
                Update(sAnswer + " " + sTime + " " + sTarget);
            //~

            //sGoStop
            int randomStop = random.Next(1, randomStopMax + 1);
            bool isStopped = false;
            if (round != 0 && randomStop == 1)
            {
                isStopped = true;
                sTargetHour4Commit = " forked!";
            }

            //실제 작업들...
            RunCommand("git pull");
            RunCommand("git status");

            //좀 가까이 잘보이게 
            Console.WriteLine("작업{0}일 국가수:{1}", WORK, capital.Length / 2);

            RunCommand("git commit --all -m "
                + "\"" + sLocation + sMingling + sPrefix + sCapital + sRound + sTargetHour4Commit + "\"");

            //home mode아닐때만
            Console.WriteLine("sLocation={0}", sLocation);
            if (sLocation == "")
                RunCommand("git push");

            Console.Write(sMingling);
            Console.Write(" randomStop={0}/{1} ", randomStop, randomStopMax);

            if (isStopped)
            {
                Console.WriteLine("현재시간={0}", sTime);
                Console.WriteLine("사고방지용 Random 종료");
                Environment.Exit(0);
            }

            if (round >= roundMax)
            {
                Console.WriteLine("현재시간={0}", sTime);
                Console.WriteLine("사고방지용 Max 종료");
                Environment.Exit(0);
            }

            // run next round
            Console.WriteLine("현재시간={3} => {0}/{1} => {2}", randomResult, thisRoundTarget, targetTime, sTime);
            Console.WriteLine("in Round {0}--------------------------------", round);

            // 알람 타이머 생성 및 시작
            myTimer = new System.Threading.Timer(Timer_Elapsed, null, 1000 * randomResult * 60, 60 * 1000 * 3);

            round++;
        }

        private static string makeTexts(ref string sLocation)
        {
            //string sLocation = "";
            FileInfo fi = new FileInfo("gc_home.cfg");
            if (fi.Exists)
                sLocation = "[home] ";
            return sLocation;
        }

        // 작업쓰레드가 지정된 시간 간격으로 아래 이벤트 핸들러 실행
        static void Timer_Tick(object sender, ElapsedEventArgs e)
        {
            Console.Write(DateTime.Now.ToString("HH:mm:ss "));
        }

        private static void Timer_Elapsed(object state)
        {
            if (myTimer != null)
                myTimer.Dispose();
            timerTick.Stop();
            RunGit();
            timerTick.Start();
        }

        static void Update(string sUpdate)
        {   
            int iNum = 0;
            string textNum;
            FileInfo fi = new FileInfo(fileGit);
            //FileInfo.Exists로 파일 존재유무 확인 "

            if (fi.Exists)
            {   //"파일존재"
                // text file 의 전체 text 를 읽어 옵니다.
                textNum = System.IO.File.ReadAllText(fileGit);
                bool isTest = int.TryParse(textNum, out iNum);
                iNum++;
            }
            else { // "파일부재" 
                //그대로 0
                Console.WriteLine("\n파일부재");
            }
            
            // Text 파일 생성 및 text 를 입력 합니다.
            textNum = Convert.ToString(iNum);

            System.IO.File.WriteAllText(fileGit, sUpdate, Encoding.Default);
            Console.WriteLine("Updating git file value================={0}", sUpdate);
        }

        static void RunCommand(string command)
        {
            System.Diagnostics.ProcessStartInfo proInfo = new System.Diagnostics.ProcessStartInfo();
            System.Diagnostics.Process pro = new System.Diagnostics.Process();
            // 실행할 파일명 입력 -- cmd
            proInfo.FileName = @"cmd";
            // cmd 창 띄우기 -- true(띄우지 않기.) false(띄우기)
            proInfo.CreateNoWindow = true;
            proInfo.UseShellExecute = false;
            // cmd 데이터 받기
            proInfo.RedirectStandardOutput = true;
            // cmd 데이터 보내기
            proInfo.RedirectStandardInput = true;
            // cmd 오류내용 받기
            proInfo.RedirectStandardError = true;
            pro.StartInfo = proInfo;
            pro.Start();
            // CMD 에 보낼 명령어를 입력 합니다.
            pro.StandardInput.Write(command + Environment.NewLine);
            pro.StandardInput.Close();
            // 결과 값을 리턴 받습니다.
            string resultValue = pro.StandardOutput.ReadToEnd();
            pro.WaitForExit();
            pro.Close();
            // 결과 값을 확인 합니다.
            Console.WriteLine(resultValue);
        }
    }
}

/* 본 App 동작설명
#기능
	1 자동 commit 및 random 종료시 email 알림?
	2  암기기능 (수도, 스페인어 숫자 )
	
Release note    
    5.          log에 수도추가, prefix 추가 new
    4.30        343 lines: home mode일때 git squash덜하게 test용이므로 update를 실행하지않게함, ga.bat -> p.bat
    4.27        실제시작 기입 시간 필요! (하루 처음 시작위치를 알아야함),
    4.24        commit에는 시간만, 파일에는 target 분단위까지 적음, 0 round추가, 
    4.21        1.국가수표시,스페인어숫자, 2.home mode push없음, 소문자화, command, cong 1/2확률로 빈칸출력(수도 집중용)
    4.19        시간에서0빼기, Force Mode:office용 한줄로 처리, from(조사)추가, 명령어 1전체소문자로.2첫자대문자(default)
    4.1         강제시작 옵션만들기 eu: 0이라 commit안되는경우있었다, 
    2021.       다음시간표시, Random종료기능, home위치확인(file식으로 쉽게), random화(command,수도), 
    2020.5.12   C#화함
    2020.2.12   python버전 시작

내부설명  
    실제 시작 기입 시간도 필요! (하루 처음 시작위치를 알아야함)
	최초는 commit없음: 내가 커밋하고싶어서 일부로 고치지 않는이상 안일어나야한다(test시용이)
        (사용자에게 선택권을 줘야함)
        commit 강제로하려면 log숫자 초기화~
    2nd round는 무조건 커밋 
    */
