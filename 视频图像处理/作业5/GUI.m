function varargout = GUI(varargin)
% GUI MATLAB code for GUI.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI

% Last Modified by GUIDE v2.5 09-Apr-2019 09:55:44

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI is made visible.
function GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI (see VARARGIN)
im = imread('inputImg.bmp');
axes(handles.inputImg);
imshow(im)
handles.im = im;
guidata(hObject, handles);
% Choose default command line output for GUI
handles.output = hObject;
handles.action = '选择功能';
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --------------------------------------------------------------------
function file_Callback(hObject, eventdata, handles)
% hObject    handle to file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function open_img_Callback(hObject, eventdata, handles)
% hObject    handle to open_img (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[filename,pathname] = uigetfile('*.jpg;*.png;*.bmp','选择图像');
imgName = fullfile(pathname,filename);
im = imread(imgName);
axes(handles.inputImg);
imshow(im);


% --- Executes on selection change in menu_select.
function menu_select_Callback(hObject, eventdata, handles)
% hObject    handle to menu_select (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% 选择功能
% 增强 Laplacian
% 去噪 NLM
% 复原 Wiener

contents = cellstr(get(hObject,'String')); % 获取下拉菜单信息
action = contents{get(hObject,'Value')}; % 返回所选项
handles.action = action;
guidata(hObject, handles);
switch action 
    case '选择功能'
    case '增强 Laplacian'
        set(handles.nlm_1, 'enable', 'off'); 
        set(handles.nlm_2, 'enable', 'off'); 
        set(handles.nlm_3, 'enable', 'off'); 
        set(handles.nlm_4, 'enable', 'off'); 
        set(handles.wiener_1, 'enable', 'off'); 
        set(handles.wiener_2, 'enable', 'off'); 
        set(handles.wiener_3, 'enable', 'off'); 
    case '去噪 NLM'
        set(handles.nlm_1, 'enable', 'on'); 
        set(handles.nlm_2, 'enable', 'on'); 
        set(handles.nlm_3, 'enable', 'on'); 
        set(handles.nlm_4, 'enable', 'on'); 
        set(handles.wiener_1, 'enable', 'off'); 
        set(handles.wiener_2, 'enable', 'off'); 
        set(handles.wiener_3, 'enable', 'off'); 
    case '复原 Wiener'
        set(handles.nlm_1, 'enable', 'off'); 
        set(handles.nlm_2, 'enable', 'off'); 
        set(handles.nlm_3, 'enable', 'off'); 
        set(handles.nlm_4, 'enable', 'off'); 
        set(handles.wiener_1, 'enable', 'on'); 
        set(handles.wiener_2, 'enable', 'on'); 
        set(handles.wiener_3, 'enable', 'on'); 
end 

% Hints: contents = cellstr(get(hObject,'String')) returns menu_select contents as cell array
%        contents{get(hObject,'Value')} returns selected item from menu_select


% --- Executes during object creation, after setting all properties.
function menu_select_CreateFcn(hObject, eventdata, handles)
% hObject    handle to menu_select (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



% --- Executes on button press in run.
function run_Callback(hObject, eventdata, handles)
% hObject    handle to run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

switch (handles.action)
    case '选择功能'
        msgbox('请选择一个功能！');
    case '增强 Laplacian'
        % pass
    case '去噪 NLM'
        contents = cellstr(get(handles.nlm_1,'String')); % 获取下拉菜单信息
        nm_1 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        contents = cellstr(get(handles.nlm_2,'String')); % 获取下拉菜单信息
        nm_2 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        contents = cellstr(get(handles.nlm_3,'String')); % 获取下拉菜单信息
        nm_3 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        contents = cellstr(get(handles.nlm_4,'String')); % 获取下拉菜单信息
        nm_4 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        outim = nlm(handles.im, nm_1, nm_2, nm_3);
    case '复原 Wiener'
        contents = cellstr(get(handles.wiener_1,'String')); % 获取下拉菜单信息
        wn_1 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        contents = cellstr(get(handles.wiener_2,'String')); % 获取下拉菜单信息
        wn_2 = str2double(contents{get(hObject,'Value')}); % 返回所选项
        contents = cellstr(get(handles.wiener_3,'String')); % 获取下拉菜单信息
        wn_3 = str2double(contents{get(hObject,'Value')}); % 返回所选项
end 
axes(outim);
imshow(im);





function wiener_1_Callback(hObject, eventdata, handles)
% hObject    handle to wiener_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wiener_1 as text
%        str2double(get(hObject,'String')) returns contents of wiener_1 as a double


% --- Executes during object creation, after setting all properties.
function wiener_1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wiener_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wiener_3_Callback(hObject, eventdata, handles)
% hObject    handle to wiener_3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wiener_3 as text
%        str2double(get(hObject,'String')) returns contents of wiener_3 as a double


% --- Executes during object creation, after setting all properties.
function wiener_3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wiener_3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function wiener_2_Callback(hObject, eventdata, handles)
% hObject    handle to wiener_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of wiener_2 as text
%        str2double(get(hObject,'String')) returns contents of wiener_2 as a double


% --- Executes during object creation, after setting all properties.
function wiener_2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to wiener_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nlm_1_Callback(hObject, eventdata, handles)
% hObject    handle to nlm_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nlm_1 as text
%        str2double(get(hObject,'String')) returns contents of nlm_1 as a double


% --- Executes during object creation, after setting all properties.
function nlm_1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nlm_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nlm_2_Callback(hObject, eventdata, handles)
% hObject    handle to nlm_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nlm_2 as text
%        str2double(get(hObject,'String')) returns contents of nlm_2 as a double


% --- Executes during object creation, after setting all properties.
function nlm_2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nlm_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nlm_3_Callback(hObject, eventdata, handles)
% hObject    handle to nlm_3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nlm_3 as text
%        str2double(get(hObject,'String')) returns contents of nlm_3 as a double


% --- Executes during object creation, after setting all properties.
function nlm_3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nlm_3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nlm_4_Callback(hObject, eventdata, handles)
% hObject    handle to nlm_4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nlm_4 as text
%        str2double(get(hObject,'String')) returns contents of nlm_4 as a double


% --- Executes during object creation, after setting all properties.
function nlm_4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nlm_4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
